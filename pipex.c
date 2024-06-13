/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:55:27 by ronanpothie       #+#    #+#             */
/*   Updated: 2024/06/13 14:00:04 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_putstr_fd(char *s, int fd)
{
	long unsigned int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		write(fd, &s[i++], 1);
}

int main()
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
}

char	*find_path(char **commands, char **envp)
{
	char	**path;

	while (ft_strncmp(*envp, "PATH=", 5) != 0)
		envp++;
	path = ft_split(*envp, ':');
	while (*path)
	{
		ft_strjoin(*path, "/");
		ft_strjoin(*path, commands[0]);
		path++;
	}
	while (*path && access(*path, X_OK) != 0)
		path++;
	return (*path);
}

void	child_1(char **argv, char **envp, int fd[2])
{
	char 	*cmd_path;
	char	**commands;
	int		second_fd;

	second_fd = open(argv[1], O_RDONLY);
	
	commands = ft_split(argv[1], ' ');
	cmd_path = find_path(commands, envp);
	dup2(1, fd[1]);
	execve(cmd_path, argv[1], envp);
}

void	child_2(char **argv, char **envp, int fd[2])
{
	char	*cmd_path;
	char	**commands;
	int		fd;

	fd = 
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;
	int		status;

	if (pipe(fd) == -1)
	{
		
	}
	pid = fork();
	
	if (pid < 0)
	{
		
	}
	if (pid == 0)
	{
		child_1(argv, envp, fd);
	}
	else
	{
		waitpid(pid, &status, 0);
		pid = fork();
		if (pid == 0)
			child_2(argv, envp, fd);
	}
	// pid = waitpid();
	
}
