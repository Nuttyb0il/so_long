/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_prepend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:49:46 by jallerha          #+#    #+#             */
/*   Updated: 2022/02/28 21:49:53 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lists.h"
#include "../includes/memory.h"

void	ft_chain_prepend(t_chain_lst **lst, void *content)
{
	t_chain_lst	*new;

	new = ft_chain_new(content);
	if (!new)
		return ;
	if ((*lst)->content == NULL && (*lst)->next == NULL && (*lst)->prev == NULL)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	(*lst)->prev = new;
	*lst = new;
}
