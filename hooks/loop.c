/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:08:50 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/27 16:43:23 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/mlx.h"

int	ft_loop_hook(t_game *game)
{
	game->game_clock++;
	ft_increment_clocks(game);
	ft_set_animation(game);
	mlx_put_image_to_window(game->mlx_ptr, game->game_window,
		game->player_image, game->x, game->y);
	return (0);
}
