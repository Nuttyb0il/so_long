/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:32:39 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/07 02:39:22 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUT_H
# define PUT_H
# include "../includes/string.h"
# include <unistd.h>

/**
 * @brief Print an integer
 * 
 * @param n The integer to print
 * @param fd The file descriptor
 * @return int Non-zero if INT_MIN is printed
 */
int		ft_putnbr_fd(int n, int fd);

/**
 * @brief Print a string and a line-feed (\n)
 * 
 * @param s The string to print
 * @param fd The file descriptor
 */
void	ft_putendl_fd(char *s, int fd);

/**
 * @brief Print a string
 * 
 * @param string The string to print
 * @param fd The file descriptor
 * @return int The number of characters printed
 */
int		ft_putstr_fd(char *string, int fd);

/**
 * @brief Print a char
 * 
 * @param c The char to print
 * @param fd The file descriptor
 * @return int The number of characters printed
 */
int		ft_putchar_fd(char c, int fd);
#endif