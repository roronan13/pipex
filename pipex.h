/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:30:26 by rpothier          #+#    #+#             */
/*   Updated: 2024/06/20 20:28:54 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <string.h>
# include <errno.h>

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

void	closing_fd(int a, int b, int c);
int		check_args(int argc);
void	second_fork(pid_t *pid, int *fd, char **argv, char **envp);
int		end_of_parent(pid_t a, pid_t b);

char	*find_path(char **commands, char **envp);
void	child_1(char **argv, char **envp, int *fd);
void	child_2(char **argv, char **envp, int *fd);

#endif