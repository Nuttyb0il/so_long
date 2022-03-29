/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:26:34 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/29 17:59:21 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/mlx.h"
#include "includes/so_long.h"
#include "libft/includes/colors.h"
#include "libft/includes/printf.h"
#include "libft/includes/constants.h"
#include "libft/includes/string.h"
#include <stdlib.h>

// TODO : print warning and show confirmation because map is too big
// (negative size)
void	ft_load_game_sprite(t_game *game, char *arg)
{
	int	size;

	if (ft_strcmp(arg, "debug") == 0)
	{
		ft_load_sprite_table_file(game, "assets/debug_x64.tbl", 228132741);
		return ;
	}
	size = ft_table_size(game->width);
	if (size == 64)
		ft_load_sprite_table_file(game, "assets/x64.tbl", 2822933351);
	else if (size == 32)
		ft_load_sprite_table_file(game, "assets/x32.tbl", 2822933351);
	else if (size == 48)
		ft_load_sprite_table_file(game, "assets/x48.tbl", 2822933351);
	else if (size < 0)
		ft_load_sprite_table_file(game, "assets/x32.tbl", 2822933351);
}

void	ft_init_game(t_game *game, char *map, char *debug)
{
	game->moves = 0;
	game->game_clock = 0;
	game->direction = DOWN;
	game->map_data = ft_load_map(map);
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		clean_exit_mlx(1, game);
	game->game_window = mlx_new_window(game->mlx_ptr,
			ft_compute_size(game->map_data.width),
			ft_compute_size(game->map_data.height),
			"so_long");
	// TODO : Check if game_window is null
	ft_load_game_sprite(game, debug);
	game->player_image = game->sprites[7].image;
	ft_render_map(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	// if (argc >= 2)
	// {
	// 	ft_fprintf(STDERR,
	// 		PURPLE1"Usage: %s%s%s <map>\n%sExample :\n\t%s%s%s maps/map_01.ber%s",
	// 		HOTPINK4, argv[0], YELLOW, PURPLE1, HOTPINK4, argv[0], YELLOW, RESET
	// 		);
	// 	clean_exit(1);
	// }
	ft_bzero(&game, sizeof(t_game));
	if (argc == 3)
		ft_init_game(&game, argv[1], "debug");
	else
		ft_init_game(&game, argv[1], "");
	mlx_hook(game.game_window, 17, 0, ft_redcross, &game);
	mlx_hook(game.game_window, 2, 1, ft_key_hook, &game);
	mlx_loop_hook(game.mlx_ptr, ft_loop_hook, &game);
	mlx_loop(game.mlx_ptr);
	clean_exit_mlx(0, &game);
	return (0);
}
