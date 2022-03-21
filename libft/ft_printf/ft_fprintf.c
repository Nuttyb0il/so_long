/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:07:39 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/08 18:25:48 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fprintf(int fd, const char *fmt, ...)
{
	unsigned int	res;
	va_list			ap;

	res = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt != '%')
			res += write(fd, fmt, 1);
		else if (*++fmt == '%')
			res += write(fd, "%%", 1);
		else if (*fmt == 'c' || *fmt == 's' || *fmt == 'p')
			res += ft_putcsp(fd, *fmt, ap);
		else if (*fmt == 'd' || *fmt == 'i')
			res += ft_putdec(va_arg(ap, int), fd);
		else if (*fmt == 'u')
			res += ft_putnbrbase(va_arg(ap, unsigned), 10, 0, fd);
		else if (*fmt == 'x' || *fmt == 'X')
			res += ft_putnbrbase(va_arg(ap, unsigned), 16, *fmt == 'x', fd);
		fmt++;
	}
	va_end(ap);
	return (res);
}
