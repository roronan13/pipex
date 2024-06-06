/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:55:27 by ronanpothie       #+#    #+#             */
/*   Updated: 2024/06/06 23:17:23 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

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
    int i = 0;
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

int	main(int argc, char **argv)
{
	int		fd[2];
	pid_t	pid;

	pipe(fd);
	pid = fork();
	
	if (pid == 0)
	{
		
	}
}
