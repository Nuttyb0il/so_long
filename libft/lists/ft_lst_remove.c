/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:15:20 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/01 17:11:45 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lists.h"
#include "../includes/memory.h"

void	ft_chain_remove(t_chain_lst **lst, void *content, size_t content_size)
{
	int	i;

	i = ft_chain_index(*lst, content, content_size);
	if (i != -1)
		ft_chain_pop(lst, i);
}
