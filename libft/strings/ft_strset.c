/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:23:15 by jallerha          #+#    #+#             */
/*   Updated: 2022/02/26 15:44:05 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/string.h"
#include <stdio.h>

char	*ft_strset(char *target, char c)
{
	int	i;

	i = 0;
	if (target)
	{
		while (target[i])
		{
			target[i] = c;
			i++;
		}
	}
	return (target);
}

char	*ft_strnset(char *target, char c, size_t n)
{
	size_t	i;

	i = 0;
	if (target)
	{
		while (i < n && target[i])
		{
			target[i] = c;
			i++;
		}
	}
	return (target);
}
