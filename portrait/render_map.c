/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:44:52 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/23 17:06:19 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/mlx.h"
#include "../libft/includes/lists.h"

void	ft_render_tile(t_game *game, char tile, int x, int y)
{
	if (tile == '0')
		ft_render_sprite_by_id(game, 2, x, y);
	else if (tile == '1')
		ft_render_sprite_by_id(game, 20, x, y);
	else if (tile == 'P')
	{
		game->x = x;
		game->y = y;
		ft_render_sprite_by_id(game, 7, x, y);
	}
	else if (tile == 'C')
		ft_render_sprite_by_id(game, 19, x, y);
	else if (tile == 'E')
		ft_render_sprite_by_id(game, 1, x, y);
}

void	ft_render_map(t_game *game)
{
	int			i;
	int			j;
	t_chain_lst	*line;
	char		*str;

	i = 0;
	j = 0;
	line = game->map_data.lines;
	while (line)
	{
		str = (char*)line->content;
		while (str[i])
		{
			ft_render_tile(game, str[i], i * 64, j * 64);
			i++;
		}
		i = 0;
		j++;
		line = line->next;
	}
}