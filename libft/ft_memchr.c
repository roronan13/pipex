/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 22:44:55 by rpothier          #+#    #+#             */
/*   Updated: 2023/12/07 16:42:16 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	a;
	unsigned char	*ptr;

	i = 0;
	a = (unsigned char)c;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		if (ptr[i] == a)
			return (&ptr[i]);
		i++;
	}
	return (NULL);
}
