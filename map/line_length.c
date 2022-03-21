/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_length.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:33:28 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/21 14:13:51 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/bool.h"

int	ft_valid_line_length(char *s, int expected)
{
	int	i;
	int	line_length;

	i = 0;
	line_length = 0;
	while (s[i])
	{
		if (s[i] == '\n' && line_length != expected)
			return (FALSE);
		else if (s[i] == '\n')
			line_length = 0;
		else
			line_length++;
		i++;
	}
	return (TRUE);
}
