/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:58:46 by jallerha          #+#    #+#             */
/*   Updated: 2022/02/10 16:14:02 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_allowed_movement(t_game *game, int keycode)
{
	t_point point;
	
	point = game->map->player_pos;
	if (keycode == DOWN)
		point.y -= PIXEL_SKIPPING;
	else if (keycode == UP)
		point.y += PIXEL_SKIPPING;
	else if (keycode == LEFT)
		point.x -= PIXEL_SKIPPING;
	else if (keycode == RIGHT)
		point.x += PIXEL_SKIPPING;
	char c = ft_get_tile(game, point);
	printf("[%s:%d] : Tile at %d, %d is a %c\n", __FILE__, __LINE__, point.x / TILE_SIZE, point.y / TILE_SIZE, c);
	return (ft_get_tile(game, point) != '1');
}