#include "../../so_long.h"

void ft_random_hair(t_sprite *sprite)
{    
    if (sprite->palette.size < 4)
        return ;
    sprite->palette.colors[1].r = ft_pseudo_random(159, 255);
    sprite->palette.colors[1].g = ft_pseudo_random(198, 255);
    sprite->palette.colors[1].b = ft_pseudo_random(194, 255);
    sprite->palette.colors[0].r = sprite->palette.colors[1].r - 45;
    sprite->palette.colors[0].g = sprite->palette.colors[1].g - 37;
    sprite->palette.colors[0].b = sprite->palette.colors[1].b - 49;
    sprite->palette.colors[3].r = sprite->palette.colors[0].r - 51;
    sprite->palette.colors[3].g = sprite->palette.colors[0].g - 20;
    sprite->palette.colors[3].b = sprite->palette.colors[0].b - 12;   
}