/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_charset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:55:44 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/21 14:10:48 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/bool.h"
#include "../libft/includes/string.h"

int	ft_valid_charset(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '0' || s[i] == '1' || s[i] == 'C'
			|| s[i] == 'E' || s[i] == 'P' || s[i] == '\n')
			i++;
		else
			return (FALSE);
	}
	return (TRUE);
}
