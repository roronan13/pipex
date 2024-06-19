/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 00:16:30 by rpothier          #+#    #+#             */
/*   Updated: 2024/01/25 16:39:53 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_sign(char a, va_list ap)
{
	int	local_nbr;

	local_nbr = 0;
	if (a == 'c')
		local_nbr = ft_printf_c(va_arg(ap, int));
	else if (a == 's')
		local_nbr = ft_printf_s(va_arg(ap, char *));
	else if (a == 'p')
		local_nbr = ft_printf_p(va_arg(ap, void *));
	else if (a == 'd' || a == 'i')
		local_nbr = ft_printf_d_i(va_arg(ap, int));
	else if (a == 'u')
		local_nbr = ft_printf_u(va_arg(ap, unsigned int));
	else if (a == 'x')
		local_nbr = ft_printf_x_low(va_arg(ap, unsigned int));
	else if (a == 'X')
		local_nbr = ft_printf_x_up(va_arg(ap, unsigned int));
	else if (a == '%')
		local_nbr = ft_printf_percent();
	return (local_nbr);
}

int	ft_printf(const char *format, ...)
{
	unsigned int	i;
	char			a;
	int				global_nbr;
	va_list			ap;

	va_start(ap, format);
	i = 0;
	global_nbr = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			a = format[i + 1];
			global_nbr += ft_sign(a, ap);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			global_nbr++;
		}
		i++;
	}
	va_end(ap);
	return (global_nbr);
}
