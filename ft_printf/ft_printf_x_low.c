/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x_low.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:19:29 by rpothier          #+#    #+#             */
/*   Updated: 2024/01/19 11:23:39 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_x_low(unsigned int n)
{
	int		nbr;
	char	*base_hexa;

	base_hexa = "0123456789abcdef";
	nbr = ft_putnbr_hexa(n, base_hexa);
	return (nbr);
}
