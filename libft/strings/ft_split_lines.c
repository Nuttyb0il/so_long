/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 21:58:25 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/01 14:25:23 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/string.h"
#include "../includes/memory.h"

t_chain_lst	*ft_split_lines(char *str)
{
	t_chain_lst	*output;

	if (ft_strstr("\r\n", str) != NULL)
		output = ft_split(str, "\r\n");
	else
		output = ft_split(str, "\n");
	return (output);
}
