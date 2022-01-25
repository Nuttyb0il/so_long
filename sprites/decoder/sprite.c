/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:29:48 by jallerha          #+#    #+#             */
/*   Updated: 2022/01/24 14:51:43 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite.h"
void ft_decode_sprite(int fd, t_sprite *sprite)
{  
    ft_get_palette(fd, &sprite->palette);
    read(fd, &sprite->compressed, 1);
    read(fd, &sprite->width, 1);
    read(fd, &sprite->height, 1);
    sprite->pixels = (t_pixel *)malloc(sizeof(t_pixel) * sprite->width * sprite->height);
    if (sprite->compressed == 0)
        ft_decode_uncompressed_sprite(fd, &sprite->pixels);
    else
        ft_decode_compressed_sprite(fd, &sprite->pixels);
}

int ft_decode_uncompressed_sprite(int fd, t_pixel **pixels)
{
    int i;

    i = 0;
    while (read(fd, &pixels[i]->palette_index, sizeof(t_pixel)) > 0)
        i++;
    return (i);
}

int ft_decode_compressed_sprite(int fd, t_pixel **pixels)
{
    int i;
    int repeat;

    unsigned char buffer[2];

    i = 0;
    while (read(fd, buffer, 2) > 0)
    {
        repeat = buffer[0];
        while (repeat > 0)
        {
            printf("pixels[%d] = %d\n", i, buffer[1]);
            // pixels[i]->palette_index = buffer[1];
            i++;
            repeat--;
        }
    }
    return (i);
}

t_sprite ft_new_sprite()
{
    t_sprite sprite;
    sprite.compressed = 0;
    sprite.width = 0;
    sprite.height = 0;
    sprite.pixels = NULL;
    sprite.palette = ft_new_palette();
    return (sprite);
}