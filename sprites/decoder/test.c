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
}