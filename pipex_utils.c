/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:20:29 by rpothier          #+#    #+#             */
/*   Updated: 2024/06/21 16:37:50 by rpothier         ###   ########.fr       */
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

void	close_and_text(int a, int b, int c, char *msg)
{
	closing_fd(a, b, c);
	perror(msg);
	exit(errno);
}

void	envp_not_found(char **commands)
{
	perror("_ENVP not found");
	ft_free_tab(commands);
	exit(errno);
}

void	path_not_found(char **commands)
{
	ft_putstr_fd("_PATH not found\n", 2);
	ft_free_tab(commands);
	exit(errno);
}

void	cmd_path_not_found(char **commands, char *msg)
{
	ft_putstr_fd(msg, 2);
	ft_free_tab(commands);
	exit(127);
}
