#include "sprite.h"
#include "mlx.h"
#include "../../so_long.h"
#include <string.h>


void ft_print_matrix(t_sprite sprite)
{
    for (int i = 0; i < sprite.height; i++)
    {
        printf("%d -> %2d | ", i, i * sprite.width);
        for (int j = 0; j < sprite.width; j++)
            printf("%2d ", sprite.pixels[i * sprite.width + j]);
        puts("");
    }
}

int ft_keyhook(int keycode, t_game *game)
{
    if (keycode == 96)
    {
        printf("Destroying\n");
        // mlx_destroy_window(game->mlx_ptr, game->win_ptr);
        ft_free_game(game);
        exit(0);
    } else if (keycode >= 123 && keycode <= 126) {
        printf("Moving\n");
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
	if (argc != 2)
		return (1);
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

    game = ft_load_game(sprites_path, sprites_name, argv[1], 4);
    if (!game.map->valid)
    {
        printf("Map is invalid\n");
        return (0); // TODO : Use ft_error
    }
    // init window
    game.mlx_ptr = mlx_init();
    game.win_ptr = mlx_new_window(game.mlx_ptr, game.map->width * 64, game.map->height * 64 + 40, "so_long");
    game.window_height = game.map->height * 64 + 30;
    game.window_width = game.map->width * 64;
    // ft_render_sprite(&game, "wall", 0, 0);
    for (size_t i = 0; i < game.map->size; i++)
    {
        printf("%c", game.map->map_string[i]);
    }
    puts("");
    ft_render_map(&game);
    ft_render_status(&game);
    mlx_hook(game.win_ptr, 2, 0, ft_keyhook, &game);
    mlx_loop(game.mlx_ptr);
    ft_free_game(&game);
    return (0);
}
