/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_capitalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 15:17:58 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/01 14:23:33 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/chartype.h"
#include "../includes/conversions.h"
#include "../includes/string.h"

void	ft_capitalize(char *str)
{
	int	i;
	int	is_new_word;

	is_new_word = 1;
	i = -1;
	while (str[++i] != '\0')
	{
		if (is_new_word)
		{
			str[i] = ft_toupper(str[i]);
			is_new_word = 0;
		}
		else
		{
			str[i] = ft_tolower(str[i]);
		}
		if (!ft_isalpha(str[i]))
		{
			is_new_word = 1;
		}
	}
}
