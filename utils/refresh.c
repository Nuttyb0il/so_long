/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:50:20 by jallerha          #+#    #+#             */
/*   Updated: 2022/02/10 17:46:32 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_point ft_get_tile_under(t_point player_pos)
{
	t_point tile;
	
	tile.x = player_pos.x / TILE_SIZE * TILE_SIZE;
	tile.y = player_pos.y / TILE_SIZE * TILE_SIZE;
	return (tile);
}

char ft_get_tile(t_game *game, t_point point)
{
	point.x /= TILE_SIZE;
	point.y /= TILE_SIZE;
	if (point.x > game->map->width || point.y > game->map->height)
		return '\0';
	return game->map->map_string[point.y * game->map->width + point.x];
}

void ft_refresh_tiles(t_game *game, t_point point)
{
	t_point tile;

	tile = ft_get_tile_under(point);
	if (ft_get_tile(game, tile) != '0')
		return ;
	ft_render_sprite(game, "tile", tile.x, tile.y);
}