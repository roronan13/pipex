/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:30:26 by rpothier          #+#    #+#             */
/*   Updated: 2024/06/21 16:40:22 by rpothier         ###   ########.fr       */
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

char	*find_path(char **commands, char **envp);
void	child_1(char **argv, char **envp, int *fd);
void	child_2(char **argv, char **envp, int *fd);

int		check_args(int argc);
void	second_fork(pid_t *pid, int *fd, char **argv, char **envp);
int		end_of_parent(pid_t a, pid_t b);

void	closing_fd(int a, int b, int c);
void	close_and_text(int a, int b, int c, char *msg);
void	envp_not_found(char **commands);
void	path_not_found(char **commands);
void	cmd_path_not_found(char **commands, char *msg);

#endif