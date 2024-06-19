/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:09:46 by rpothier          #+#    #+#             */
/*   Updated: 2024/01/19 11:36:02 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	int		i;
	char	a;

	i = 0;
	if (n <= 9)
	{
		a = 48 + n;
		write(1, &a, 1);
		i = 1;
	}
	else
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	return (i);
}
