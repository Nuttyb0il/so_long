/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 22:59:04 by jallerha          #+#    #+#             */
/*   Updated: 2022/04/06 01:23:42 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/printf.h"
#include "../libft/includes/conversions.h"
#include "../libft/includes/memory.h"

void	ft_render_number(t_game *game, int n, int x)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_itoa(n);
	while (str[i])
	{
		ft_render_sprite_by_id(game, (str[i] - 48) + 34, x,
			game->win_height - game->size);
		x += game->size;
		i++;
	}
	ft_free(&str);
}
