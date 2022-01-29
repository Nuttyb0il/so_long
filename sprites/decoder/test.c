#include "sprite.h"
#include "mlx.h"
#include <string.h>

int ft_pseudo_random(int max);

int color_to_hex(int index, t_palette palette)
{
    if (index == 0xFF)
        return (-1);
    int r = palette.colors[index].r;
    int g = palette.colors[index].g;
    int b = palette.colors[index].b;

    return ((r << 16) | (g << 8) | b);
}

void ft_print_matrix(t_sprite sprite)
{
    for (int i = 0; i < sprite.height; i++)
    {
        printf("%d -> %2d | ", i, i * sprite.width);
        for (int j = 0; j < sprite.width; j++)
            printf("%2d ", sprite.pixels[i * sprite.width + j].palette_index);
        puts("");
    }
}

void ft_key_hook(int keycode, void *window)
{
    if (keycode == 65307)
        exit(0);
}

int main(int argc, char **argv)
{
    char possibilities[5][60] = {
        "../../game_sprites/madeline_0.sprite",
        "../../game_sprites/madeline_1.sprite",
        "../../game_sprites/madeline_2.sprite",
        "../../game_sprites/madeline_3.sprite",
        "../../game_sprites/madeline_4.sprite"
    };
    char *selected_sprite = possibilities[ft_pseudo_random(4)];
    puts("Portrait C decoder.");
    int fd = open(selected_sprite, O_RDONLY);
    // check if file is open
    if (fd == -1)
    {
        printf("Error: file not found\n");
        return (0);
    }
    t_sprite sprite;

    sprite = ft_new_sprite();
    ft_decode_sprite(fd, &sprite);
    puts("Sprite decoding ended.\n------------");
    printf("Compressed : %d\n", sprite.compressed);
    printf("Palette size : %d\n", sprite.palette.size);
    printf("Width: %d\n", sprite.width);
    printf("Height: %d\n", sprite.height);
    printf("Matrix:\n");
    if (sprite.height * sprite.width > 1000)
        printf("Too big to print -> %d\n", sprite.height * sprite.width);
    else
        ft_print_matrix(sprite);
    char *filename = strdup(selected_sprite);
    void *mlx_ptr = mlx_init();
    void *win_ptr = mlx_new_window(mlx_ptr, 300, 300, filename);

    for (int i = 0; i < sprite.height; i++)
    {
        for (int j = 0; j < sprite.width; j++)
        {
            int color = sprite.pixels[i * sprite.width + j].palette_index;
            int hex = color_to_hex(color, sprite.palette);
            if (hex > 0)
                mlx_pixel_put(mlx_ptr, win_ptr, j, i, hex);
        }
    }
    // register esc key
    mlx_key_hook(win_ptr, ft_key_hook, win_ptr);
    
    // show window
    mlx_loop(mlx_ptr);
}