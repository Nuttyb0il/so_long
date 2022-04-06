/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:22:48 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/01 14:29:06 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lists.h"

void	ft_chain_reverse(t_chain_lst **lst)
{
	t_chain_lst	*current;
	t_chain_lst	*next;
	t_chain_lst	*prev;

	if ((*lst)->content == NULL && (*lst)->next == NULL && (*lst)->prev == NULL)
		return ;
	current = *lst;
	prev = NULL;
	while (current)
	{
		next = current->next;
		current->next = prev;
		current->prev = next;
		prev = current;
		current = next;
	}
	*lst = prev;
}
