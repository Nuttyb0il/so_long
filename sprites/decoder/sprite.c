/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:29:48 by jallerha          #+#    #+#             */
/*   Updated: 2022/02/02 17:14:21 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_decode_sprite(char *name, char *path, t_sprite *sprite)
{
	int	fd;

	ft_new_sprite(name, sprite);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		// TODO : Send error
		return ;
	ft_get_palette(fd, &sprite->palette);
	read(fd, &sprite->compressed, 1);
	read(fd, &sprite->width, 1);
	read(fd, &sprite->height, 1);
	ft_init_matrix(sprite->height, sprite->width, sprite);
	sprite->name = ft_strdup(name);
	if (sprite->compressed == 0)
		ft_decode_uncompressed_sprite(fd, &sprite->pixels, sprite->width * sprite->height);
	else
		ft_decode_compressed_sprite(fd, &sprite->pixels, sprite->width * sprite->height);
}

void	ft_decode_uncompressed_sprite(int fd, int **pixels, int size)
{
	int	i;

	i = 0;
	while (i < size)
		read(fd, &(*pixels)[i++], 1);
}

void	ft_decode_compressed_sprite(int fd, int **pixels, int size)
{
	int				i;
	int				offset;
	unsigned char	buffer[2];

	i = 0;
	offset = 0;
	while (offset < size)
	{
		if (read(fd, &buffer, 2) <= 0)
			break ;
		if ((buffer[0] != 0x4D && buffer[1] != 0x49) || (buffer[0] != 0x4B && buffer[1] != 0x4F))
		{
			buffer[0]++;
			offset += buffer[0];
			if (buffer[0] == 1)
				(*pixels)[i++] = buffer[1];
			else
			{
				while (buffer[0]-- > 0)
					(*pixels)[i++] = buffer[1];
			}
		}
		else
			break ;
	}
}

void	ft_new_sprite(char *name, t_sprite *sprite)
{
	sprite->compressed = 0;
	sprite->width = 0;
	sprite->height = 0;
	sprite->pixels = NULL;
	sprite->palette = ft_new_palette();
	sprite->name = name;
}

void	ft_init_matrix(int height, int width, t_sprite *sprite)
{
	int	matrix_size;

	matrix_size = width * height;
	sprite->pixels = (int *)malloc(sizeof(int) * matrix_size);
}
