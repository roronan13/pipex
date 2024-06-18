/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ronanpothier <ronanpothier@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:55:27 by ronanpothie       #+#    #+#             */
/*   Updated: 2024/06/18 21:18:36 by ronanpothie      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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
	int		i;
	
	i = 0;
	while (*envp && ft_strncmp(*envp, "PATH=", 5) != 0)
		envp++;
	paths = ft_split(*envp + 5, ':');
	if (!paths)
	{
		//ft_free_tab(paths);
		return (NULL);
	}
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
	//i = 0;
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
		close(fd[0]);
		close(fd[1]);
		//close(second_fd);
		perror("_OPENING INFILE failed");
		exit(errno);
	}
	if (dup2(second_fd, 0) == -1)
	{
		close(fd[0]);
		close(fd[1]);
		close(second_fd);
		perror("_FIRST DUP2 failed");
		exit(errno);
	}
	close(second_fd);
	if (dup2(fd[1], 1) == -1)
	{
		close(fd[0]);
		close(fd[1]);
		perror("_SECOND DUP2 failed");
		exit(errno);
	}
	close(fd[0]);
	close(fd[1]);
	commands = ft_split(argv[2], ' ');
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
		close(fd[0]);
		close(fd[1]);
		//close(second_fd);
		perror("_OPENING OUTFILE failed");
		exit(errno);
	}
	if (dup2(fd[0], 0) == -1)
	{
		close(fd[0]);
		close(fd[1]);
		close(second_fd);
		perror("_FIRST DUP2 failed");
		exit(errno);
	}
	close(fd[0]);
	close(fd[1]);
	if (dup2(second_fd, 1) == -1)
	{
		close(second_fd);
		perror("_SECOND DUP2 failed");
		exit(errno);
	}
	close(second_fd);
	commands = ft_split(argv[3], ' ');
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
	int		status;

	if (argc != 5)
	{
		printf("_you need 4 ARGUMENTS.");
		return (1);
	}
	
	if (pipe(fd) == -1)
	{
		/* free(fd);
		free(pid); */
		perror("_PIPE failed");
		return (1);
	}
	
	pid[0] = fork();
	
	if (pid[0] < 0)
	{
		/* free(pid);
		free(fd); */
		close(fd[0]);
		close(fd[1]);
		perror("_FIRST FORK failed");
		return (1);
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
			perror("_SECOND FORK failed");
			close(fd[0]);
			close(fd[1]);
			return (1);
		}
		if (pid[1] == 0)
		{
			child_2(argv, envp, fd);
		}
	}
	
	close(fd[0]);
	close(fd[1]);
	
	if (waitpid(pid[0], &status, 0) == -1)
	{
		perror("_WAITPID FOR CHILD 1 failed");
		return (1);
	}
	if (waitpid(pid[1], &status, 0) == -1)
	{
		perror("_WAITPID FOR CHILD 2 failed");
		return (1);
	}
	
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (0);
}
