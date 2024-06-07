/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:16:08 by rpothier          #+#    #+#             */
/*   Updated: 2023/12/07 16:52:36 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	size_s1;
	size_t	size_s2;

	if (!s1 || !s2)
		return (NULL);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	ptr = malloc(sizeof(char) * (size_s1 + size_s2 + 1));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, size_s1 + 1);
	ft_strlcat(ptr, s2, size_s1 + size_s2 + 1);
	return (ptr);
}
