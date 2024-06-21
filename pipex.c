/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:55:27 by ronanpothie       #+#    #+#             */
/*   Updated: 2024/06/21 16:04:15 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **commands, char **envp)
{
	char	**paths;
	char	*new_path_1;
	char	*new_path_2;
	int		i;

	i = -1;
	if (!envp)
		envp_not_found(commands);
	while (*envp && ft_strncmp(*envp, "PATH=", 5) != 0)
		envp++;
	if (!*envp)
		path_not_found(commands);
	paths = ft_split(*envp + 5, ':');
	if (!paths)
		return (NULL);
	while (paths[++i])
	{
		new_path_1 = ft_strjoin(paths[i], "/");
		new_path_2 = ft_strjoin(new_path_1, commands[0]);
		free(new_path_1);
		if (new_path_2 && access(new_path_2, X_OK) == 0)
			return (ft_free_tab(paths), new_path_2);
		free(new_path_2);
	}
	return (ft_free_tab(paths), NULL);
}

void	child_1(char **argv, char **envp, int *fd)
{
	char	*cmd_path;
	char	**commands;
	int		second_fd;

	second_fd = open(argv[1], O_RDONLY);
	if (second_fd == -1)
		close_and_text(fd[0], fd[1], -1, "_OPENING INFILE failed");
	if (dup2(second_fd, 0) == -1)
		close_and_text(fd[0], fd[1], second_fd, "_FIRST DUP2 failed");
	close(second_fd);
	if (dup2(fd[1], 1) == -1)
		close_and_text(fd[0], fd[1], -1, "_SECOND DUP2 failed");
	closing_fd(fd[0], fd[1], -1);
	commands = ft_split(argv[2], ' ');
	if (!commands)
		exit((perror("_MALLOC failed"), errno));
	cmd_path = find_path(commands, envp);
	if (!cmd_path)
		cmd_path_not_found(commands, "_COMMAND 1 not found\n");
	if (execve(cmd_path, commands, envp) == -1)
	{
		perror("_FIRST EXECVE failed");
		ft_free_tab(commands);
		exit((free(cmd_path), errno));
	}
}

void	child_2(char **argv, char **envp, int *fd)
{
	char	*cmd_path;
	char	**commands;
	int		second_fd;

	second_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (second_fd == -1)
		close_and_text(fd[0], fd[1], -1, "_OPENING OUTFILE failed");
	if (dup2(fd[0], 0) == -1)
		close_and_text(fd[0], fd[1], second_fd, "_FIRST DUP2 failed");
	closing_fd(fd[0], fd[1], -1);
	if (dup2(second_fd, 1) == -1)
		close_and_text(second_fd, -1, -1, "_SECOND DUP2 failed");
	close(second_fd);
	commands = ft_split(argv[3], ' ');
	if (!commands)
		exit((perror("_MALLOC failed"), errno));
	cmd_path = find_path(commands, envp);
	if (!cmd_path)
		cmd_path_not_found(commands, "_COMMAND 2 not found\n");
	if (execve(cmd_path, commands, envp) == -1)
	{
		perror("_SECOND EXECVE failed");
		ft_free_tab(commands);
		exit((free(cmd_path), errno));
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid[2];

	if (check_args(argc))
		return (1);
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
		second_fork(pid, fd, argv, envp);
	closing_fd(fd[0], fd[1], -1);
	return (end_of_parent(pid[0], pid[1]));
}
