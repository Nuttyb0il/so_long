/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:47:54 by yfoucade          #+#    #+#             */
/*   Updated: 2022/03/08 18:10:29 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../includes/string.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

unsigned int	ft_putchar(char c, int fd);
unsigned int	ft_putstr(char *s, int fd);

size_t			ft_putnbrbase(unsigned long long nbr, char base,
					char lower, int fd);
size_t			ft_putdec(long long nbr, int fd);
size_t			ft_puthex(unsigned long nbr, int fd);
size_t			ft_putcsp(int fd, char converter, va_list ap);

#endif
