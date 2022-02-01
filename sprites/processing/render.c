#include "../../so_long.h"
#include "mlx.h"

t_sprite *ft_sprite_name(char *name, t_game *game)
{
    int i;

    i = 0;
    while (i < game->sprite_count)
    {
        if (ft_strncmp(game->sprites[i].name, name, 3) == 0)
            return (&game->sprites[i]);
        i++;
    }
    return (&game->sprites[0]);
}

int color_to_hex(int index, t_palette palette)
{
    if (index == 0xFF)
        return (-1);
    int r = palette.colors[index].r;
    int g = palette.colors[index].g;
    int b = palette.colors[index].b;

    return ((r << 16) | (g << 8) | b);
}

void ft_render_sprite(t_game *game, char *name, int offset_x, int offset_y)
{
    int x;
    int y;
    int hex;
    int color;
    t_sprite sprite;

    x = 0;
    y = 0;
    sprite = *ft_sprite_name(name, game);
    if (!game->win_ptr || !game->mlx_ptr || offset_x < 0 || offset_y < 0)
        return ;
    while (y < sprite.height)
    {
        while (x < sprite.width)
        {
            color = sprite.pixels[y * sprite.width + x];
            hex = color_to_hex(color, sprite.palette);
            if (hex > 0)
                mlx_pixel_put(game->mlx_ptr, game->win_ptr, x + offset_x, y + offset_y, hex);
            x++;
        }
        x = 0;
        y++;
    }
}

char *ft_render_tile(char c)
{
    if (c == '1')
        return "stone";
    else if (c == '0')
        return "ice";
    else if (c == 'C')
        return "berry";
    else if (c == 'P')
        return "ice";
    else if (c == 'E')
        return "ice";
    return "";
}

void ft_render_map(t_game *game)
{
    int x;
    int y;
    int i;
    char tile;

    x = 0;
    y = 0;
    i = 0;
    if (!game->win_ptr || !game->mlx_ptr)
        return ;
    // read every tile in the map, skip \n
    while (i < game->map->size)
    {
        tile = game->map->map_string[i];
        if (tile == '\n')
        {
            y++;
            x = 0;
        }
        else
        {
            ft_render_sprite(game, "ice", x * TILE_SIZE, y * TILE_SIZE);
            if (tile != '0')
                ft_render_sprite(game, ft_render_tile(tile), x * TILE_SIZE, y * TILE_SIZE);
            x++;
        }
        i++;
    }
}