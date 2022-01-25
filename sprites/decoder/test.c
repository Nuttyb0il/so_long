#include "sprite.h"

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

    puts("Sprite decoding ended.\n------------");
    printf("Compressed : %d\n", sprite.compressed);
    printf("Palette size : %d\n", sprite.palette.size);
    printf("Width: %d\n", sprite.width);
    printf("Height: %d\n", sprite.height);
    printf("Matrix:\n");
    for (int i = 0; i < sprite.height; i++)
    {
        printf("%d -> %2d | ", i, i * sprite.width);
        for (int j = 0; j < sprite.width; j++)
            printf("%2d ", sprite.pixels[i * sprite.width + j].palette_index);
        puts("");
    }
}