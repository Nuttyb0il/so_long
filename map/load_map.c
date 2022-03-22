/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:41:38 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/22 12:11:45 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/printf.h"
#include "../libft/includes/colors.h"
#include "../libft/includes/constants.h"
#include "../libft/includes/string.h"
#include "../libft/includes/memory.h"
#include "../libft/includes/file.h"

int	ft_open_file(char *path)
{
	int		fd;
	char	*copy;

	copy = ft_strdup(path);
	ft_strlwr(copy);
	if (ft_endswith(copy, ".ber"))
		fd = open(path, O_RDONLY);
	else
	{
		ft_fprintf(STDERR,
			RED2"Error: "INDIANRED1"'%s'"ORANGE2" is not a map file\n"RESET, path
			);
		clean_exit(ERROR);
	}
	ft_free(&copy);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_fprintf(STDERR,
			RED2"Error: "ORANGE2"failed to open : "INDIANRED1"'%s'\n"RESET, path
			);
		clean_exit(ERROR);
	}
	close(fd);
	return (TRUE);
}

int	ft_markdown_code(t_map *map)
{
	if (map->collectibles <= 0)
		return (INVALID_COLLECTIBLES);
	if (map->spawns <= 0)
		return (INVALID_SPAWNS);
	if (map->exits <= 0)
		return (INVALID_EXITS);
	if (!ft_valid_charset(map->map))
		return (INVALID_MAP_CHARACTERS);
	if (!ft_valid_line_length(map->lines, map->width))
		return (INVALID_LINE_LENGTH);
	if (!ft_map_closed(map->lines))
		return (MAP_NOT_CLOSED);
	return (0);
}

int	ft_sanity_check(t_map *map)
{
	int		i;
	int		invalid_elements;

	i = 0;
	map->height = ft_chain_count(map->lines);
	while (map->map[i] && map->map[i] != '\n')
		i++;
	map->width = i;
	map->collectibles = ft_count_words(map->map, "C");
	map->spawns = ft_count_words(map->map, "P");
	map->exits = ft_count_words(map->map, "E");
	invalid_elements = ft_markdown_code(map);
	if (invalid_elements != 0)
		ft_print_markdown(invalid_elements, map);
	return (TRUE);
}

t_map	ft_load_map(char *path)
{
	t_map	map;

	if (!ft_is_ber(path))
	{
		ft_fprintf(STDERR,
			RED2"Error: "ORANGE2"%s"RED2" is not a map file\n"RESET, path
			);
		clean_exit(1);
	}
	ft_open_file(path);
	map.map = ft_read_file(path);
	map.lines = ft_split(map.map, "\n");
	map.length = ft_strlen(map.map);
	map.sanity = ft_sanity_check(&map);
	return (map);
}
