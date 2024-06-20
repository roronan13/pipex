/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:55:27 by ronanpothie       #+#    #+#             */
/*   Updated: 2024/06/20 18:39:01 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **commands, char **envp)
{
	char	**paths;
	char	*new_path_1;
	char	*new_path_2;
	int		i;
	
	i = 0;
	if (!envp)
	{
		perror("_ENVP not found");
		ft_free_tab(commands);
		exit(errno);
	}
	while (*envp && ft_strncmp(*envp, "PATH=", 5) != 0)
		envp++;
	if (!*envp)
	{
		ft_putstr_fd("_PATH not found\n", 2);
		ft_free_tab(commands);
		exit(errno);
	}
	paths = ft_split(*envp + 5, ':');
	if (!paths)
		return (NULL);
	while (paths[i])
	{
		new_path_1 = ft_strjoin(paths[i], "/");
		new_path_2 = ft_strjoin(new_path_1, commands[0]);
		free(new_path_1);
		if (new_path_2 && access(new_path_2, X_OK) == 0)
		{
			ft_free_tab(paths);
			return (new_path_2);
		}
		free(new_path_2);
		i++;
	}
	ft_free_tab(paths);
	return (NULL);
}

void	child_1(char **argv, char **envp, int *fd)
{
	char 	*cmd_path;
	char	**commands;
	int		second_fd;

	second_fd = open(argv[1], O_RDONLY);
	if (second_fd == -1)
	{
		closing_fd(fd[0], fd[1], -1);
		perror("_OPENING INFILE failed");
		exit(errno);
	}
	if (dup2(second_fd, 0) == -1)
	{
		closing_fd(fd[0], fd[1], second_fd);
		perror("_FIRST DUP2 failed");
		exit(errno);
	}
	close(second_fd);
	if (dup2(fd[1], 1) == -1)
	{
		closing_fd(fd[0], fd[1], -1);
		perror("_SECOND DUP2 failed");
		exit(errno);
	}
	closing_fd(fd[0], fd[1], -1);
	commands = ft_split(argv[2], ' ');
	if (!commands)
	{
		perror("_MALLOC failed");
		exit(errno);
	}
	cmd_path = find_path(commands, envp);
	if (!cmd_path)
	{
		ft_putstr_fd("_COMMAND 1 not found\n", 2);
		ft_free_tab(commands);
		exit(127);
	}
	if (execve(cmd_path, commands, envp) == -1)
	{
		perror("_FIRST EXECVE failed");
		ft_free_tab(commands);
		free(cmd_path);
		exit(errno);
	}
}

void	child_2(char **argv, char **envp, int *fd)
{
	char	*cmd_path;
	char	**commands;
	int		second_fd;

	second_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (second_fd == -1)
	{
		closing_fd(fd[0], fd[1], -1);
		perror("_OPENING OUTFILE failed");
		exit(errno);
	}
	if (dup2(fd[0], 0) == -1)
	{
		closing_fd(fd[0], fd[1], second_fd);
		perror("_FIRST DUP2 failed");
		exit(errno);
	}
	closing_fd(fd[0], fd[1], -1);
	if (dup2(second_fd, 1) == -1)
	{
		close(second_fd);
		perror("_SECOND DUP2 failed");
		exit(errno);
	}
	close(second_fd);
	commands = ft_split(argv[3], ' ');
	if (!commands)
	{
		perror("_MALLOC failed");
		exit(errno);
	}
	cmd_path = find_path(commands, envp);
	if (!cmd_path)
	{
		ft_putstr_fd("_COMMAND 2 not found\n", 2);
		ft_free_tab(commands);
		exit(127);
	}
	if (execve(cmd_path, commands, envp) == -1)
	{
		perror("_SECOND EXECVE failed");
		ft_free_tab(commands);
		free(cmd_path);
		exit(errno);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid[2];

	if (argc != 5)
	{
		ft_printf("_you need 4 ARGUMENTS.\n");
		return (1);
	}
	if (pipe(fd) == -1)
	{
		perror("_PIPE failed");
		return (1);
	}
	pid[0] = fork();
	if (pid[0] < 0)
	{
		closing_fd(fd[0], fd[1], -1);
		perror("_FIRST FORK failed");
		return (1);
	}
	if (pid[0] == 0)
		child_1(argv, envp, fd);
	else
	{
		pid[1] = fork();
		if (pid[1] < 0)
		{
			perror("_SECOND FORK failed");
			closing_fd(fd[0], fd[1], -1);
			return (1);
		}
		if (pid[1] == 0)
			child_2(argv, envp, fd);
	}
	closing_fd(fd[0], fd[1], -1);
	return (end_of_parent(pid[0], pid[1]));
}
