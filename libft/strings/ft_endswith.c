/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endswith.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 19:11:17 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/01 14:22:07 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/string.h"

int	ft_endswith(char *s, char *suffix)
{
	int	i;
	int	j;

	if (ft_strlen(s) < ft_strlen(suffix))
		return (0);
	i = ft_strlen(s) - ft_strlen(suffix);
	j = 0;
	while (suffix[j])
	{
		if (s[i] != suffix[j])
			return (0);
		i++;
		j++;
	}
	return (1);
}
