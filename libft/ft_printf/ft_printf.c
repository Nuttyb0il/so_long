/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:48:00 by yfoucade          #+#    #+#             */
/*   Updated: 2022/03/08 18:09:18 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../includes/constants.h"

int	ft_printf(const char *fmt, ...)
{
	unsigned int	res;
	va_list			ap;

	res = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt != '%')
			res += write(STDOUT, fmt, 1);
		else if (*++fmt == '%')
			res += write(STDOUT, "%%", 1);
		else if (*fmt == 'c' || *fmt == 's' || *fmt == 'p')
			res += ft_putcsp(STDOUT, *fmt, ap);
		else if (*fmt == 'd' || *fmt == 'i')
			res += ft_putdec(va_arg(ap, int), STDOUT);
		else if (*fmt == 'u')
			res += ft_putnbrbase(va_arg(ap, unsigned), 10, 0, STDOUT);
		else if (*fmt == 'x' || *fmt == 'X')
			res += ft_putnbrbase(va_arg(ap, unsigned), 16, *fmt == 'x', STDOUT);
		fmt++;
	}
	va_end(ap);
	return (res);
}
