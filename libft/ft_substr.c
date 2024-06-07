/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:48:39 by rpothier          #+#    #+#             */
/*   Updated: 2023/12/07 16:21:23 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		ptr = malloc(sizeof(char) * 1);
		if (!ptr)
			return (NULL);
		ptr[i] = '\0';
		return (ptr);
	}
	if (len > ft_strlen(s) - start)
		ptr = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	while (s[start] && i < len)
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	return (ptr);
}
