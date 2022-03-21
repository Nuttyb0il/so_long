/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:08:01 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/01 15:16:00 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include <unistd.h>

/**
 * @brief A function that can be passed to a sort function, 
 *  used to sort integers in ascending order
 * @param n1 N-th integer
 * @param n2 N+1-th integer
 */
int		int_asc_comparator(void *n1, void *n2);

/**
 * @brief A function that can be passed to a sort function, 
 *  used to sort double in ascending order
 * @param n1 N-th double
 * @param n2 N+1-th double
 */
int		double_asc_comparator(void *n1, void *n2);

/**
 * @brief A function that can be passed to a sort function, 
 *  used to sort float in ascending order
 * @param n1 N-th float
 * @param n2 N+1-th float
 */
int		float_asc_comparator(void *n1, void *n2);

/**
 * @brief A function that can be passed to a sort function, 
 *  used to sort char in ascending order
 * @param n1 N-th char
 * @param n2 N+1-th char
 */
int		char_asc_comparator(void *n1, void *n2);

/**
 * @brief A function that can be passed to a sort function, 
 *  used to sort integers in descending order
 * @param n1 N-th integer
 * @param n2 N+1-th integer
 */
int		int_desc_comparator(void *n1, void *n2);

/**
 * @brief A function that can be passed to a sort function, 
 *  used to sort double in descending order
 * @param n1 N-th double
 * @param n2 N+1-th double
 */
int		double_desc_comparator(void *n1, void *n2);

/**
 * @brief A function that can be passed to a sort function, 
 *  used to sort float in descending order
 * @param n1 N-th float
 * @param n2 N+1-th float
 */
int		float_desc_comparator(void *n1, void *n2);

/**
 * @brief A function that can be passed to a sort function, 
 *  used to sort char in descending order
 * @param n1 N-th char
 * @param n2 N+1-th char
 */
int		char_desc_comparator(void *n1, void *n2);
#endif