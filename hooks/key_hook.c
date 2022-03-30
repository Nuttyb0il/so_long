/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:09:41 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/30 15:01:56 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/mlx.h"

void	ft_compute_new_position(int direction, int *x, int *y, int size)
{
	if (direction == UP)
		(*y) -= size;
	if (direction == DOWN)
		(*y) += size;
	if (direction == LEFT)
		(*x) -= size;
	if (direction == RIGHT)
		(*x) += size;
}

int	ft_key_hook(int keycode, t_game *game)
{
	int	x;
	int	y;

	x = game->x;
	y = game->y;
	if (keycode == ESC)
		clean_exit_mlx(0, game);
	if (keycode == UP || keycode == DOWN || keycode == RIGHT || keycode == LEFT)
	{
		game->direction = keycode;
		if (!ft_legal_move(keycode, game))
			return (0);
		ft_compute_new_position(keycode, &game->x, &game->y, game->tile_size);
		if (ft_get_tile_at(game, x / game->tile_size, y / game->tile_size) != 'E')
		{
			mlx_put_image_to_window(game->mlx_ptr, game->game_window,
				game->player_image, game->x, game->y);
			ft_render_sprite_by_id(game, 0, x, y);
		}
		else
			ft_render_sprite_by_id(game, 32, x, y);
	}
	return (0);
}
