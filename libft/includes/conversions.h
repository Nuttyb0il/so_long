/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:51:56 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/08 22:37:07 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSIONS_H
# define CONVERSIONS_H

/**
 * @brief  Converts a string to an integer.
 * 
 * @param c The string to be converted.
 * @return int The integer value of the character. Returns 0 if invalid format.
 */
int			ft_atoi(const char *s);

/**
 * @brief Converts a string to a long.
 * 
 * @param s The string to be converted.
 * @return long The long value of the string. Returns 0 if invalid format.
 */
long		ft_atol(const char *s);

/**
 * @brief Converts a string to a long long.
 * 
 * @param s The string to be converted.
 * @return long long The long log value of the string. 
 * Returns 0 if invalid format.
 */
long long	ft_atoll(const char *s);

/**
 * @brief Converts an integer to a string.
 * 
 * @param n 
 * @return char* A free-able string containing the integer.
 */
char		*ft_itoa(int n);

/**
 * @brief Converts a char to uppercase.
 * 
 * @param c The character to convert.
 * @return char The uppercase character.
 */
char		ft_toupper(char c);

/**
 * @brief Converts a char to lowercase.
 * 
 * @param c The character to convert.
 * @return char The lowercase character.
 */
char		ft_tolower(char c);
#endif