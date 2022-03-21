/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chartype.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:53:11 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/01 14:44:43 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARTYPE_H
# define CHARTYPE_H

/**
 * @brief  Checks if a character is an ascii character.
 * 
 * @param c The character to be checked.
 * @return int 1 if it is an ascii character, 0 otherwise.
 */
int	ft_isascii(int c);

/**
 * @brief  Checks if a character is blank (space or tab).
 * 
 * @param c The character to be checked.
 * @return int 1 if it is a blank character, 0 otherwise.
 */
int	ft_isblank(int c);

/**
 * @brief  Checks if a character is a digit. [0-9]
 * 
 * @param c The character to be checked.
 * @return int 1 if it is a digit, 0 otherwise.
 */
int	ft_isdigit(int c);

/**
 * @brief  Checks if a character is printable (ASCII 32-126).
 * 
 * @param c The character to be checked.
 * @return int 1 if it is printable, 0 otherwise.
 */
int	ft_isprint(int c);

/**
 * @brief  Checks if a character is an alphabetical character. [A-Za-z]
 * 
 * @param c The character to be checked.
 * @return int 1 if it is an alphabetical character, 0 otherwise.
 */
int	ft_isalpha(int c);

/**
 * @brief  Checks if a character is alphanumerical. [A_Za-z0-9]
 * 
 * @param c The character to be checked.
 * @return int 1 if is alphanumerical, 0 otherwise.
 */
int	ft_isalnum(int c);

/**
 * @brief  Checks if a character is a control character. (ASCII 0-31)
 * 
 * @param c The character to be checked.
 * @return int 1 if it is a control character, 0 otherwise.
 */
int	ft_iscntrl(int c);

/**
 * @brief Check if a character is a graph character. (ASCII 33-126)
 * 
 * @param c The character to be checked.
 * @return int 1 if it is a graph character, 0 otherwise.
 */
int	ft_isgraph(int c);

/**
 * @brief  Checks if a character is a lowercase character. [a-z]
 * 
 * @param c The character to be checked.
 * @return int 1 if it is a lowercase character, 0 otherwise.
 */
int	ft_islower(int c);

/**
 * @brief  Checks if a character is a punctuation character.
 * 
 * @param c The character to be checked.
 * @return int 1 if it is a punctuation character, 0 otherwise.
 */
int	ft_ispunct(int c);

/**
 * @brief  Checks if a character is one of these -> [space, \n, \t, \v, \f, \r]
 * 
 * @param c The character to be checked.
 * @return int 1 if it is a space character, 0 otherwise.
 */
int	ft_isspace(int c);

/**
 * @brief  Checks if a character is a character in base 16. [0-9, A-F, a-f]
 * 
 * @param c The character to be checked.
 * @return int 1 if it is a character in base 16, 0 otherwise.
 */
int	ft_isxdigit(int c);

/**
 * @brief  Checks if a character is an uppercase character. [A-Z]
 * 
 * @param c The character to be checked.
 * @return int 1 if it is an uppercase character, 0 otherwise.
 */
int	ft_isupper(int c);
#endif