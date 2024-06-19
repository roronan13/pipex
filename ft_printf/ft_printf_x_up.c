/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x_up.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:05:51 by rpothier          #+#    #+#             */
/*   Updated: 2024/01/19 11:23:35 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_x_up(unsigned int n)
{
	int		nbr;
	char	*base_up_hexa;

	base_up_hexa = "0123456789ABCDEF";
	nbr = ft_putnbr_hexa(n, base_up_hexa);
	return (nbr);
}
