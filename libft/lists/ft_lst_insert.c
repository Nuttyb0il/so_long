/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:17:01 by jallerha          #+#    #+#             */
/*   Updated: 2022/02/26 14:16:11 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lists.h"

void	ft_chain_insert(t_chain_lst **lst, void *content, int index)
{
	t_chain_lst	*new;
	t_chain_lst	*current;

	index++;
	if (!lst || !content)
		return ;
	if (index == 0)
	{
		ft_chain_prepend(lst, content);
		return ;
	}
	current = *lst;
	while (--index && current)
		current = current->next;
	if (!current)
		return ;
	new = ft_chain_new(content);
	if (!new)
		return ;
	new->next = current;
	new->prev = current->prev;
	current->prev->next = new;
	current->prev = new;
}
