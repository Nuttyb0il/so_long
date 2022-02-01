/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:55:19 by jallerha          #+#    #+#             */
/*   Updated: 2022/01/29 16:53:24 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

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
    // palette = malloc(sizeof(t_palette));
    read(fd, &palette->size, 1);
    bytes_to_read = palette->size * 3;
    palette->colors = (t_color*) malloc(sizeof(t_color) * palette->size);
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