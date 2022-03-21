/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:10:02 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/01 15:37:28 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lists.h"
#include "../includes/string.h"

int	ft_chain_index(t_chain_lst *lst, void *content, size_t content_size)
{
	int		i;

	i = 0;
	while (lst)
	{
		if (ft_memcmp(lst->content, content, content_size) == 0)
			return (i);
		lst = lst->next;
		i++;
	}
	return (-1);
}
