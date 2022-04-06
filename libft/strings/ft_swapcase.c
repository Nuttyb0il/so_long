/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapcase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:25:15 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/01 14:23:40 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/chartype.h"
#include "../includes/conversions.h"

void	ft_swapcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isupper(str[i]))
			str[i] = ft_tolower(str[i]);
		else if (ft_islower(str[i]))
			str[i] = ft_toupper(str[i]);
		i++;
	}
}
