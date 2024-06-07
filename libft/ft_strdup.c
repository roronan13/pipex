/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:13:04 by rpothier          #+#    #+#             */
/*   Updated: 2023/11/08 16:43:40 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	a;

	a = ft_strlen(s);
	ptr = malloc(sizeof(char) * a + 1);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s, a + 1);
	return (ptr);
}
