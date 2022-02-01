#include "../../so_long.h"

void ft_free_game(t_game *game)
{
    ft_free_sprites(game);
    if (game->mlx_ptr && game->win_ptr)
        mlx_destroy_window(game->mlx_ptr, game->win_ptr);
    free(game->map->map_string);
    free(game->map);
}

void ft_free_sprites(t_game *game)
{
    int i;

    i = 0;
    if (game->sprites)
    {
        while (i < game->sprite_count)
        {
            if (game->sprites[i].name)
                free(game->sprites[i].name);
            if (game->sprites[i].pixels)
                free(game->sprites[i].pixels);
            if (game->sprites[i].palette.colors)
                free(game->sprites[i].palette.colors);
            i++;
        }
        free(game->sprites);
    }
}