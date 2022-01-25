/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:55:19 by jallerha          #+#    #+#             */
/*   Updated: 2022/01/25 11:41:54 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color ft_read_color(int fd)
{
    t_color color;

    read(fd, &color.r, 1);
    read(fd, &color.g, 1);
    read(fd, &color.b, 1);
    return (color);
}

void ft_get_palette(int fd, t_palette *palette)
{
    int bytes_to_read;
    int i;
    
    i = 0;
    read(fd, &palette->size, 1);
    bytes_to_read = palette->size * 3;
    palette->colors = malloc(sizeof(t_color) * palette->size);
    while (i < bytes_to_read)
    {
        palette->colors[i / 3] = ft_read_color(fd);
        i += 3;
    }
}

t_palette ft_new_palette()
{
    t_palette palette;

    palette.size = 0;
    palette.colors = NULL;
    return (palette);
}