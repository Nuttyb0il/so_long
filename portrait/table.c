/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 19:58:45 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/27 16:58:18 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/lists.h"
#include "../libft/includes/file.h"
#include "../libft/includes/string.h"
#include "../libft/includes/conversions.h"
#include "../libft/includes/memory.h"

t_chain_lst	*ft_read_table(t_game *game, char *path, unsigned int crc32)
{
	t_chain_lst	*lines;
	char		*content;

	if (!ft_exists(path))
		ft_load_fail(game, path);
	if (!ft_malloc(&game->sprites, sizeof(t_sprite), SPRITE_COUNT))
		clean_exit_mlx(1, game);
	ft_bzero(game->sprites, sizeof(t_sprite) * SPRITE_COUNT);
	content = ft_read_file(path);
	if (content == NULL)
		clean_exit_mlx(1, game);
	if (ft_crc32b(content) != crc32)
		ft_integrity_table_fail(game, path);
	lines = ft_split(content, "\n");
	ft_free(&content);
	return (lines);
}

t_table	ft_parse_line(t_game *game, t_chain_lst *line)
{
	char		*line_str;
	t_table		output;
	t_chain_lst	*slices;

	if (line == NULL)
		clean_exit_mlx(1, game);
	line_str = (char *) line->content;
	if (ft_count_words(line_str, ",") != 1)
		clean_exit_mlx(1, game);
	slices = ft_split(line_str, ",");
	output.xpm_path = (char *) ft_chain_get(slices, 0)->content;
	output.crc32 = ft_atoui(ft_chain_get(slices, 1)->content);
	ft_chain_clear(&slices);
	return (output);
}
