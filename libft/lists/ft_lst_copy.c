/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:07:30 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/01 14:29:23 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lists.h"

t_chain_lst	*ft_chain_copy(t_chain_lst *lst)
{
	t_chain_lst	*output;
	t_chain_lst	*tmp;

	output = ft_chain_new(lst->content);
	if (!output)
		return (NULL);
	tmp = lst;
	tmp = tmp->next;
	while (tmp)
	{
		ft_chain_append(&output, tmp->content);
		tmp = tmp->next;
	}
	return (output);
}
