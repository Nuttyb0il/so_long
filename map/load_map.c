/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:02:12 by jallerha          #+#    #+#             */
/*   Updated: 2022/02/02 13:05:47 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "../so_long.h"

int	ft_get_size(char *path)
{
	int		fd;
	int		size;
	char	buffer[1024];
	int		read_bytes;

	size = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	while (1)
	{
		read_bytes = read(fd, buffer, 1024);
		if (read_bytes <= 0)
			break ;
		size += read_bytes;
	}
	close(fd);
	return (size);
}

void	ft_buffer_map(char *path, t_map *map)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		map->size = 0;
		return ;
	}
	map->size = ft_get_size(path);
	map->map_string = malloc(sizeof(char) * map->size);
	if (read(fd, map->map_string, map->size) == -1)
	{
		map->valid = 0;
		return ;
	}
	close(fd);
	map->valid = 1;
	map->width = 0;
	map->height = 0;
	if (map->size <= 16)
	{
		map->valid = 0;
		return ;
	}
	ft_get_attributes(map);
}

void	ft_get_attributes(t_map *map)
{
	unsigned int	i;
	unsigned int	line_width;

	i = 0;
	line_width = 0;
	while (i < map->size && map->valid == 1)
	{
		if (map->map_string[i] == '\n')
		{
			map->height++;
			if (line_width != map->width && map->width != 0)
				map->valid = 0;
			else
				map->width = line_width;
			line_width = 0;
		}
		else
			line_width++;
		if (map->map_string[i] == 'P')
		{
			map->player_pos.x = (i - 1) % map->width * TILE_SIZE;
			map->player_pos.y = (i - 1) / map->width * TILE_SIZE;
		}
		i++;
	}
}
