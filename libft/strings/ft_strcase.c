/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:48:47 by jallerha          #+#    #+#             */
/*   Updated: 2022/02/26 15:36:21 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/string.h"
#include "../includes/chartype.h"

void	ft_strlwr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_isupper(s[i]))
			s[i] += 32;
		i++;
	}
}

void	ft_strupr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_islower(s[i]))
			s[i] -= 32;
		i++;
	}
}
