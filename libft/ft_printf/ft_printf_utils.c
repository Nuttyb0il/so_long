/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:54:17 by yfoucade          #+#    #+#             */
/*   Updated: 2022/03/08 18:10:39 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_putchar(char c, int fd)
{
	return (write(fd, &c, 1));
}

unsigned int	ft_putstr(char *s, int fd)
{
	unsigned int	res;

	if (s == NULL)
		return (write(fd, "(null)", 6));
	res = ft_strlen(s);
	return (write(fd, s, res));
}
