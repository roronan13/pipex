/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:33:17 by rpothier          #+#    #+#             */
/*   Updated: 2023/11/22 23:38:54 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	long unsigned int	i;
	char				*ptr;
	unsigned char		a;

	i = 0;
	ptr = (char *)s;
	a = (unsigned char)c;
	if (a == '\0')
	{
		while (s[i])
			i++;
		ptr = (char *)&s[i];
		return (ptr);
	}
	while (s[i] != a && s[i])
		i++;
	if (s[i] == a)
	{
		ptr = (char *)&s[i];
		return (ptr);
	}
	return (NULL);
}
