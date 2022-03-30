/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:44:52 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/30 15:02:48 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/mlx.h"
#include "../libft/includes/lists.h"
#include "../libft/includes/memory.h"

void	ft_render_tile(t_game *game, char tile, int x, int y)
{
	if (tile == '0')
		ft_render_sprite_by_id(game, 0, x, y);
	else if (tile == '1')
		ft_render_sprite_by_id(game, 1, x, y);
	else if (tile == 'P')
	{
		game->x = x;
		game->y = y;
		ft_render_sprite_by_id(game, 6, x, y);
	}
	else if (tile == 'C')
	{
		ft_render_sprite_by_id(game, 18, x, y);
	}
	else if (tile == 'E')
		ft_render_sprite_by_id(game, 28, x, y);
}

void	ft_render_map(t_game *game)
{
	int			i;
	int			j;
	t_chain_lst	*line;
	char		*str;

	i = -1;
	j = 0;
	line = game->map_data.lines;
	ft_init_animations(game);
	while (line)
	{
		str = (char *) line->content;
		while (str[++i])
		{
			if (str[i] == 'E')
				ft_register_berry_animation(game, i * game->tile_size, j * game->tile_size);
			if (str[i] == 'C')
				ft_register_seed_animation(game, i * game->tile_size, j * game->tile_size);
			ft_render_tile(game, str[i], i * game->tile_size, j * game->tile_size);
		}
		i = -1;
		j++;
		line = line->next;
	}
}
