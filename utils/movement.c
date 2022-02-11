/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:20:46 by jallerha          #+#    #+#             */
/*   Updated: 2022/02/10 16:08:20 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_offset_position(int *x, int *y, int keycode)
{
	if (keycode == DOWN)
		*y -= PIXEL_SKIPPING;
	else if (keycode == UP)
		*y += PIXEL_SKIPPING;
	else if (keycode == LEFT)
		*x -= PIXEL_SKIPPING;
	else if (keycode == RIGHT)
		*x += PIXEL_SKIPPING;
}

void	ft_move_player(t_game *game, int keycode)
{
	if (ft_allowed_movement(game, keycode))
	{
		ft_refresh_tiles(game, game->map->player_pos);
		ft_offset_position(&game->map->player_pos.x,
			&game->map->player_pos.y, keycode);
		ft_render_sprite(game, "madeline", game->map->player_pos.x,
			game->map->player_pos.y);
	}
}
