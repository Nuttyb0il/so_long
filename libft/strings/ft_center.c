/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_center.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 19:51:24 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/01 14:25:08 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/memory.h"
#include "../includes/string.h"

char	*ft_center(char *s, int padding)
{
	char	*output;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!ft_malloc(&output, sizeof(char), ft_strlen(s) + padding + 1))
		return (NULL);
	while (i < padding / 2)
	{
		output[i] = ' ';
		i++;
	}
	while (s[j])
	{
		output[i] = s[j];
		i++;
		j++;
	}
	while (i < padding + ft_strlen(s))
		output[i++] = ' ';
	output[i] = '\0';
	return (output);
}
