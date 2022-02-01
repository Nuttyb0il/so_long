#include "../so_long.h"
void ft_offset_position(int *x, int *y, int keycode)
{
    if (keycode == 126)
        *y -= 5;
    else if (keycode == 125)
        *y += 5;
    else if (keycode == 123)
        *x -= 5;
    else if (keycode == 124)
        *x += 5;
}

void ft_move_player(t_game *game, int keycode)
{
    ft_offset_position(&game->map->player_x, &game->map->player_y, keycode);
    ft_render_sprite(game, "madeline", game->map->player_x, game->map->player_y);
    printf("Rendering player at %d, %d\n", game->map->player_x, game->map->player_y);
}