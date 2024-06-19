/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:58:56 by rpothier          #+#    #+#             */
/*   Updated: 2024/06/19 14:13:29 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *object, ...);
int		ft_printf_c(int c);
int		ft_printf_s(char *s);
int		ft_printf_p(void *ptr);
int		ft_printf_d_i(int n);
int		ft_printf_u(unsigned int n);
int		ft_printf_x_low(unsigned int n);
int		ft_printf_x_up(unsigned int n);
int		ft_printf_percent(void);
// int		ft_strlen(const char *s);
int		ft_putnbr(int n);
int		ft_putnbr_unsigned(unsigned int n);
int		ft_putnbr_hexa(unsigned long int n, char *base_hexa);

#endif