/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:30:35 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/07 02:40:19 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTS_H
# define LISTS_H

# include <unistd.h>

typedef struct s_chain_lst
{
	void				*content;
	struct s_chain_lst	*next;
	struct s_chain_lst	*prev;
}				t_chain_lst;
/**
 * @brief Count number of items in chained list.
 * 
 * @param lst The chained list.
 * @return int The number of items in the chained list.
 */
int			ft_chain_count(t_chain_lst *lst);

/**
 * @brief Find and returns the index of an item in a chained list.
 * 
 * @param lst The chained list.
 * @param content The item to search.
 * @param content_size The size of the content (sizeof(content_type)).
 * @return int The index of the item in the chained list.
 */
int			ft_chain_index(t_chain_lst *lst,
				void *content, size_t content_size);

/**
 * @brief Returns a copy of the list
 * 
 * @param lst The chained list to copy.
 * @return t_chain_lst* The copy of the list
 */
t_chain_lst	*ft_chain_copy(t_chain_lst *lst);

/**
 * @brief Returns the first item of a chained list.
 * 
 * @param lst The list to get the first item from.
 * @return t_chain_lst* The first item of the list.
 */
t_chain_lst	*ft_chain_first(t_chain_lst *lst);

/**
 * @brief Returns the last item of a chained list.
 * 
 * @param lst The list to get the last item from.
 * @return t_chain_lst* The last item of the list.
 */
t_chain_lst	*ft_chain_last(t_chain_lst *lst);

/**
 * @brief Create and return a new chained list, 
 * use ft_chain_init if you do not have a default value for the chained list.
 * @param content The content of the first item of the list.
 * @return t_chain_lst* 
 */
t_chain_lst	*ft_chain_new(void *content);

/**
 * @brief Initialize a chained list, fill the structure with 0x00.
 * 
 * @return t_chain_lst* The freshly initialized chained list.
 */
t_chain_lst	*ft_chain_init(void);

/**
 * @brief Returns item at index in a chained list.
 * 
 * @param lst The list to get the item from.
 * @param index The index of the item to get.
 * @return t_chain_lst* The item at index.
 */
t_chain_lst	*ft_chain_get(t_chain_lst *lst, int index);

/**
 * @brief Append a new item to a chained list.
 * 
 * @param lst The list to append the item to.
 * @param content The content of the item to append.
 */
void		ft_chain_append(t_chain_lst **lst, void *content);

/**
 * @brief Clear and free the node,
 * consider freeing everything in the chained list if needed.
 * 
 * @param lst The node to start clearing from 
 * (if first, the whole list will be cleared).
 */
void		ft_chain_clear(t_chain_lst **lst);

/**
 * @brief Insert a new item at index in a chained list.
 * 
 * @param lst The list to insert the item to.
 * @param content The content of the item to insert.
 * @param index The index to insert the item at.
 */
void		ft_chain_insert(t_chain_lst **lst, void *content, int index);

/**
 * @brief Prepend (insert at the beginning) a new item to a chained list.
 * 
 * @param lst The list to prepend the item to.
 * @param content The content of the item to prepend.
 */
void		ft_chain_prepend(t_chain_lst **lst, void *content);

/**
 * @brief Remove an item from a chained list. (remove the first occurrence)
 * 
 * @param lst The list to remove the item from.
 * @param content The content of the item to remove.
 * @param content_size The size of the content (sizeof(content_type)).
 */
void		ft_chain_remove(t_chain_lst **lst,
				void *content, size_t content_size);

/**
 * @brief Reverse the passed list.
 * 
 * @param lst A pointer to the chained list to reverse.
 */
void		ft_chain_reverse(t_chain_lst **lst);

/**
 * @brief Remove an item at index, and returns the item removed.
 * 
 * @param lst The list to remove the item from.
 * @param index The index of the item to remove.
 * @return void* The item removed.
 */
void		*ft_chain_pop(t_chain_lst **lst, int index);
#endif