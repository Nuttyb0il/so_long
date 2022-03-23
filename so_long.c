/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:26:34 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/23 20:09:13 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/mlx.h"
#include "includes/so_long.h"
#include "libft/includes/colors.h"
#include "libft/includes/printf.h"
#include "libft/includes/constants.h"
#include "libft/includes/string.h"
#include <stdlib.h>

int	ft_compute_size(int	n)
{
	return (n * 64);
}

int redcross(t_game *game)
{
	clean_exit_mlx(0, game);
	return (0);
}

int movement(int keycode, t_game *game)
{
	int	x;
	int	y;

	x = game->x;
	y = game->y;
	if (keycode == ESC)
		clean_exit_mlx(0, game);
	if (!ft_legal_move(keycode, game))
		return (0);
	if (keycode == UP)
		game->y -= 64;
	if (keycode == DOWN)
		game->y += 64;
	if (keycode == LEFT)
		game->x -= 64;
	if (keycode == RIGHT)
		game->x += 64;
	if (keycode == UP || keycode == DOWN || keycode == RIGHT || keycode == LEFT)
	{
		if (ft_get_tile_at(game, x / 64, y / 64) != 'E')
			ft_render_sprite_by_id(game, 2, x, y);
		else
			ft_render_sprite_by_id(game, 1, x, y);
		mlx_put_image_to_window(game->mlx_ptr, game->game_window,
			game->player_image, game->x, game->y);
	}
	return (0);
}

int	animation(int keycode, t_game *game)
{
	// game->game_clock++;
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		width;
	int		height;

	if (argc != 2)
	{
		ft_fprintf(STDERR,
			PURPLE1"Usage: %s%s%s <map>\n%sExample :\n\t%s%s%s maps/map_01.ber%s",
			HOTPINK4, argv[0], YELLOW, PURPLE1, HOTPINK4, argv[0], YELLOW, RESET
			);
		clean_exit(1);
	}
	ft_bzero(&game, sizeof(t_game));
	game.moves = 0;
	game.game_clock = 0;
	game.map_data = ft_load_map(argv[1]);
	game.mlx_ptr = mlx_init();
	ft_load_sprites(&game);
	game.game_window = mlx_new_window(game.mlx_ptr,
		ft_compute_size(game.map_data.width),
		ft_compute_size(game.map_data.height),
		"so_long");
	ft_render_map(&game);
	game.player_image = game.sprites[7].image;
	mlx_hook(game.game_window, 17, 0, redcross, &game);
	mlx_hook(game.game_window, 2, 1, movement, &game);
	mlx_loop_hook(game.mlx_ptr, animation, &game);
	mlx_loop(game.mlx_ptr);
	clean_exit_mlx(0, &game);
	return (0);
}