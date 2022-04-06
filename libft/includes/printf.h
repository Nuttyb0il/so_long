/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 15:07:09 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/08 18:25:37 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

/**
 * @brief Format a print a string (c, s, x, X, p, %, i, d) in STDOUT
 * 
 * @param format The format string
 * @param ... The arguments
 * @return int The number of characters printed
 */
int				ft_printf(const char *format, ...);

/**
 * @brief Format a print a string (c, s, x, X, p, %, i, d) in fd
 * 
 * @param fd The file descriptor (use constants.h to use standard outputs)
 * @param format The format string
 * @param ...  The arguments
 * @return int  The number of characters printed
 */
int				ft_fprintf(int fd, const char *format, ...);
#endif