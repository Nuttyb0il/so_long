/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:29:48 by jallerha          #+#    #+#             */
/*   Updated: 2022/01/25 14:37:51 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite.h"
void ft_decode_sprite(int fd, t_sprite *sprite)
{
    ft_get_palette(fd, &sprite->palette);
    read(fd, &sprite->compressed, 1);
    read(fd, &sprite->width, 1);
    read(fd, &sprite->height, 1);
    ft_init_matrix(sprite->height, sprite->width, sprite);
    if (sprite->compressed == 0)
        ft_decode_uncompressed_sprite(fd, &sprite->pixels, sprite->width * sprite->height);
    else
        ft_decode_compressed_sprite(fd, &sprite->pixels, sprite->width * sprite->height);
}

void ft_decode_uncompressed_sprite(int fd, t_pixel **pixels, int size)
{
    int i;

    i = 0;
    while (i < size)
        read(fd, &(*pixels)[i++].palette_index, 1);
}

void ft_decode_compressed_sprite(int fd, t_pixel **pixels, int size)
{
    int i;
    int offset;
    unsigned char buffer[2];

    i = 0;
    offset = 0;
    while (offset < size)
    {
        read(fd, &buffer, 2);
        buffer[0]++;
        if (buffer[0] == 1)
            (*pixels)[i++].palette_index = buffer[1];
        else
        {
            while (buffer[0]-- > 0)
                (*pixels)[i++].palette_index = buffer[1];
        }
        offset++;
    }
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

t_pixel ft_new_pixel()
{
    t_pixel pixel;

    pixel.palette_index = 0;
    return (pixel);
}

void ft_init_matrix(int height, int width, t_sprite *sprite)
{
    int matrix_size;
    
    matrix_size = width * height;
    sprite->pixels = (t_pixel *)malloc(sizeof(t_pixel) * matrix_size);
    printf("pixel matrix : %p\n", &sprite->pixels);
    while (matrix_size--)
        sprite->pixels[matrix_size] = ft_new_pixel();
}