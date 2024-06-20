/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:28:52 by rpothier          #+#    #+#             */
/*   Updated: 2024/06/20 21:26:15 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	closing_fd(int a, int b, int c)
{
	if (a != -1)
		close(a);
	if (b != -1)
		close(b);
	if (c != -1)
		close(c);
}

int	end_of_parent(pid_t a, pid_t b)
{
	int	status;

	if (waitpid(a, &status, 0) == -1)
	{
		perror("_WAITPID FOR CHILD 1 failed");
		return (1);
	}
	if (waitpid(b, &status, 0) == -1)
	{
		perror("_WAITPID FOR CHILD 2 failed");
		return (1);
	}
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (0);
}

int	check_args(int argc)
{
	if (argc != 5)
	{
		ft_printf("_you need 4 ARGUMENTS.\n");
		return (1);
	}
	else
		return (0);
}

void	second_fork(pid_t *pid, int *fd, char **argv, char **envp)
{
	pid[1] = fork();
	if (pid[1] < 0)
	{
		perror("_SECOND FORK failed");
		closing_fd(fd[0], fd[1], -1);
		exit(1);
	}
	if (pid[1] == 0)
		child_2(argv, envp, fd);
}
