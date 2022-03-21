/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_startswith.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 19:11:18 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/01 14:25:54 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/string.h"

int	ft_startswith(char *s, char *prefix)
{
	int	i;

	i = 0;
	if (ft_strlen(s) < ft_strlen(prefix))
		return (0);
	while (prefix[i])
	{
		if (s[i] != prefix[i])
			return (0);
		i++;
	}
	return (1);
}
