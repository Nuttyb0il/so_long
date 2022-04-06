/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:24:52 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/01 14:44:26 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSERT_H
# define ASSERT_H
# include "../includes/string.h"

/**
 * @brief    Asserts a condition.
 * 
 * @param condition The condition to be asserted.
 */
void	assert(int condition);

/**
 * @brief   Asserts a condition, but prints a message if assertion fails.
 * 
 * @param condition The condition to be asserted.
 * @param msg     The message to be printed if assertion fails.
 */
void	assert_msg(int condition, char *msg);

/**
 * @brief  Asserts a condition, print a message in any case.
 * 
 * @param condition  The condition to be asserted.
 * @param fail 	 The message to be printed if assertion fails.
 * @param success  The message to be printed if assertion succeeds.
 */
void	assert_verbose(int condition, char *fail, char *success);
#endif