#include "../../so_long.h"
void ft_render_status(t_game *game)
{
    int left_top_x = 0;
    int left_top_y = game->window_height - 30;
    int right_bottom_x = game->window_width;
    int right_bottom_y = game->window_height + 30;

    while (left_top_y < right_bottom_y)
    {
        while (left_top_x < right_bottom_x)
        {
            if (left_top_y < game->window_height - 28)
                mlx_pixel_put(game->mlx_ptr, game->win_ptr, left_top_x, left_top_y, 0xFF00FF);
            else
                mlx_pixel_put(game->mlx_ptr, game->win_ptr, left_top_x, left_top_y, 0xFFFFFF);
            left_top_x++;
        }
        left_top_x = 0;
        left_top_y++;
    }
}