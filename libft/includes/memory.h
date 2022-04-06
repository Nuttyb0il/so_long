/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:43:03 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/19 16:17:08 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H
# include <stdlib.h>

typedef struct s_alloc_lst {
	void				*ptr;
	struct s_alloc_lst	*next;
}	t_alloc_lst;

/**
 * @brief Malloc a passed pointer, and adds it to a chained list
 * 
 * @param ptr The pointer to malloc
 * @param type_size sizeof(type)
 * @param size n-bytes to allocate if type
 * @return int 0 if success, -1 if error
 */
int		ft_malloc(void *ptr, const size_t type_size, const size_t size);

/**
 * @brief Free a pointer malloc'd using ft_free, double free safe
 * 
 * @param ptr The pointer to free
 * @return int 0 if success, -1 if error
 */
int		ft_free(void *ptr);

/**
 * @brief Free all pointers malloc'd using ft_malloc, double free safe
 * 
 * @return int 0 if success, -1 if error
 */
int		ft_full_free(void);

/**
 * @brief Returns a copy of ptr, realloc'd to new_size
 * 
 * @param ptr The pointer to reallocate
 * @param new_size Size of the new pointer
 */
void	*ft_realloc(void *ptr, size_t new_size);
#endif