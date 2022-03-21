/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 21:59:49 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/01 14:29:54 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lists.h"
#include "../includes/memory.h"
#include "../includes/string.h"

t_chain_lst	*ft_chain_init(void)
{
	t_chain_lst	*lst;

	if (!ft_malloc(&lst, sizeof(t_chain_lst), 1))
		return (NULL);
	ft_bzero(lst, sizeof(t_chain_lst));
	return (lst);
}
