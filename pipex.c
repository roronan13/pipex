/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:55:27 by ronanpothie       #+#    #+#             */
/*   Updated: 2024/06/17 17:46:21 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* int main()
{
    int pid;
    int status;
    // int i = 0;
    int fd[2];
    char str[1000];


    pipe(fd);

	// fd[0] = open("a", O_RDONLY);
	// fd[1] = open("a", O_WRONLY);
    pid = fork();
    if (pid < 0)
        return (0);
    if (pid == 0)
    {
        
      // ft_putstr_fd("allo", fd[1]);
      dup2(fd[1], 1);
	  write(1, "lol\n", 4);
	  dup2(1, fd[0]);
       close(fd[1]);
       close(fd[0]);
      printf("prout\n");
       // printf("enfant : %d, %d\n", pid, getpid());
        // exit(3);
    }
	
    else
    {
        waitpid(pid, &status, 0);
        dup2(fd[0], 0);
        read(fd[0], str, 1000);
        printf("parent : %s\n", str);
        close(fd[1]);
        close(fd[0]);
       // printf("parent : %d, %d\n", pid, getpid());
        if (WIFEXITED(status))
        {
            //printf("%d\n", WEXITSTATUS(status));
        }
    }
	if (pid == 0)
		while (1)
		{
			printf ("lol");
		}
  //  printf("allo\n");
    return (0);
} */

char	*find_path(char **commands, char **envp)
{
	char	**paths;
	char	*new_path_1;
	char	*new_path_2;
	
	while (ft_strncmp(*envp, "PATH=", 5) != 0)
		envp++;
	paths = ft_split(*envp + 5, ':');
	while (*paths)
	{
		new_path_1 = ft_strjoin(*paths, "/");
		new_path_2 = ft_strjoin(new_path_1, commands[0]);
		free(new_path_1);
		if (new_path_2 && access(new_path_2, X_OK) == 0)
			return (new_path_2);
		free(new_path_2);
		paths++;
	}
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
		// close(fd[0]);
		// close(fd[1]);
		close(second_fd);
		perror("opening infile failed");
		exit(errno);
	}
	if (dup2(second_fd, 0) == -1)
	{
		close(second_fd);
		perror("first dup2 failed");
		exit(errno);
	}
	close(second_fd);
	if (dup2(fd[1], 1) == -1)
	{
		perror("second dup2 failed");
		exit(errno);
	}
	close(fd[0]);
	close(fd[1]);
	commands = ft_split(argv[2], ' ');
	cmd_path = find_path(commands, envp);
	execve(cmd_path, commands, envp);
}

void	child_2(char **argv, char **envp, int *fd)
{
	char	*cmd_path;
	char	**commands;
	int		second_fd;

	second_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(fd[0], 0);
	close(fd[0]);
	close(fd[1]);
	dup2(second_fd, 1);
	close(second_fd);
	commands = ft_split(argv[3], ' ');
	cmd_path = find_path(commands, envp);
	execve(cmd_path, commands, envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid[2];
	int		status;

	if (argc != 5)
	{
		printf("you need 4 arguments.");
		return (1);
	}
	
	if (pipe(fd) == -1)
	{
		/* free(fd);
		free(pid); */
		perror("pipe failed");
	}
	
	pid[0] = fork();
	
	if (pid[0] < 0)
	{
		/* free(pid);
		free(fd); */
		perror("first fork failed");
	}
	
	if (pid[0] == 0)
	{
		child_1(argv, envp, fd);
	}
	
	else
	{
		pid[1] = fork();
		if (pid[1] < 0)
		{
			perror("second fork failed");
		}
		if (pid[1] == 0)
		{
			child_2(argv, envp, fd);
		}
	}
	
	close(fd[0]);
	close(fd[1]);
	waitpid(pid[0], &status, 0);
	waitpid(pid[1], &status, 0);
	
	return (0);
}
