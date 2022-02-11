/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:04:22 by jallerha          #+#    #+#             */
/*   Updated: 2022/02/10 14:19:27 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprites/decoder/sprite.h"
#include "mlx.h"
#include "so_long.h"
#include <string.h>

int ft_keyhook(int keycode, t_game *game)
{
	if (keycode == 96)
	{
		// mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		ft_free_game(game);
		exit(0);
	} else if (keycode >= 123 && keycode <= 126) {
		ft_move_player(game, keycode);
	} else if (keycode == 117) { // DEL
		mlx_clear_window(game->mlx_ptr, game->win_ptr);
		ft_place_ice(game);
		ft_render_map(game);
	}
	return (0);
}

int main(int argc, char **argv)
{
	printf("[%s:%d] : starting\n", __FILE__, __LINE__);
	if (argc != 2)
		return (1);
	printf("[%s:%d] : valid args\n", __FILE__, __LINE__);
	t_game game;

	char **sprites_path;
	char **sprites_name;
	sprites_path = malloc(sizeof(char *) * 3);
	sprites_name = malloc(sizeof(char *) * 3);
	sprites_path[0] = ft_strdup("game_sprites/ice.cnv");
	sprites_name[0] = ft_strdup("ice");
	sprites_path[1] = ft_strdup("game_sprites/stone.cnv");
	sprites_name[1] = ft_strdup("stone");
	sprites_path[2] = ft_strdup("game_sprites/berry.cnv");
	sprites_name[2] = ft_strdup("berry");
	sprites_path[3] = ft_strdup("game_sprites/madeline.cnv");
	sprites_name[3] = ft_strdup("madeline");
	printf("[%s:%d] : sprite table was setup\n", __FILE__, __LINE__);
	game = ft_load_game(sprites_path, sprites_name, argv[1], 4);
	if (!game.map->valid)
	{
		printf("[%s:%d] : map was marked as invalid.\n", __FILE__, __LINE__);
		return (0); // TODO : Use ft_error
	}
	// init window
	printf("[%s:%d] : init mlx\n", __FILE__, __LINE__);
	game.mlx_ptr = mlx_init();
	game.win_ptr = mlx_new_window(game.mlx_ptr, game.map->width * 64, game.map->height * 64 + 40, "so_long");
	printf("[%s:%d] : init mlx window\n", __FILE__, __LINE__);
	game.window_height = game.map->height * 64 + 40;
	game.window_width = game.map->width * 64;
	// ft_render_sprite(&game, "wall", 0, 0);
	printf("[%s:%d] : rendering map\n", __FILE__, __LINE__);
	ft_render_map(&game);
	printf("[%s:%d] : player pos was set to %d, %d\n", __FILE__, __LINE__, game.map->player_pos.x, game.map->player_pos.y);
	// ft_render_status(&game);
	printf("[%s:%d] : hooking keys\n", __FILE__, __LINE__);
	mlx_hook(game.win_ptr, 2, 0, ft_keyhook, &game);
	printf("[%s:%d] : game loop\n", __FILE__, __LINE__);
	mlx_loop(game.mlx_ptr);
	printf("[%s:%d] : freeing game\n", __FILE__, __LINE__);
	ft_free_game(&game);
	return (0);
}
