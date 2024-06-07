/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:33:55 by rpothier          #+#    #+#             */
/*   Updated: 2023/11/01 17:57:13 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*ptr_dest;
	char	*ptr_src;

	i = 0;
	ptr_dest = (char *)dest;
	ptr_src = (char *)src;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		ptr_dest[i] = ptr_src[i];
		i++;
	}
	return (ptr_dest);
}
