/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:58:33 by rpothier          #+#    #+#             */
/*   Updated: 2023/11/02 14:15:33 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*ptr_dest;
	unsigned const char	*ptr_src;
	size_t				j;

	i = n - 1;
	j = n - 1;
	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned const char *)src;
	if (ptr_src < ptr_dest)
	{
		while (n)
		{
			ptr_dest[j--] = ptr_src[i--];
			n--;
		}
		return (ptr_dest);
	}
	ptr_dest = ft_memcpy(dest, src, n);
	return (ptr_dest);
}
