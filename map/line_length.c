/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_length.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:33:28 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/27 16:32:25 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/bool.h"
#include "../libft/includes/lists.h"
#include "../libft/includes/string.h"

int	ft_valid_line_length(t_chain_lst *lines, int expected)
{
	t_chain_lst	*tmp;

	tmp = lines;
	while (tmp)
	{
		if (ft_strlen(tmp->content) != expected)
			return (FALSE);
		tmp = tmp->next;
	}
	return (TRUE);
}
