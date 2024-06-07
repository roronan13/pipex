/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 22:06:58 by rpothier          #+#    #+#             */
/*   Updated: 2023/11/23 00:25:14 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	long unsigned int	i;
	unsigned char		a;

	i = 0;
	a = (unsigned char)c;
	while (s[i])
		i++;
	if (a == '\0')
		return ((char *)&s[i]);
	else
	{
		while (s[i] != a && i > 0)
			i--;
		if (s[i] == a)
			return ((char *)&s[i]);
		else
			return (NULL);
	}
}
