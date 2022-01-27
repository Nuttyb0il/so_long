#include "sprite.h"
#include "mlx.h"
#include <string.h>

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

int main(int argc, char **argv)
{
    puts("Portrait C decoder.");
    int fd = open(argv[1], O_RDONLY);
    // check if file is open
    if (fd == -1)
    {
        printf("Error: file not found\n");
        return (0);
    }
    t_sprite sprite;

    sprite = ft_new_sprite();
    ft_decode_sprite(fd, &sprite);
    char *filename = strdup(argv[1]);
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
    // show window
    mlx_loop(mlx_ptr);
}