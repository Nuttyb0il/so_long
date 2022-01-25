#ifndef SPRITE_H
# define SPRITE_H
# include "color.h"
# include "pixel.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
typedef struct	s_sprite
{
    t_palette	palette;
    t_pixel		*pixels;
    int			width;
    int			height;
    int         compressed;
}				t_sprite;

void ft_decode_sprite(int fd, t_sprite *sprite);
void ft_decode_uncompressed_sprite(int fd, t_pixel **pixels, int size);
void ft_decode_compressed_sprite(int fd, t_pixel **pixels, int size);
t_sprite ft_new_sprite();
void ft_init_matrix(int height, int width, t_sprite *sprite);
#endif