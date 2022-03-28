/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:46:57 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/27 16:59:30 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/mlx.h"
#include "../libft/includes/lists.h"
#include "../libft/includes/memory.h"
#include "../libft/includes/printf.h"
#include "../libft/includes/colors.h"
#include "../libft/includes/constants.h"
#include "../libft/includes/string.h"
#include "../libft/includes/file.h"

void	check_integrity(t_game *game, char *path, unsigned int crc32)
{
	if (ft_crc32b(ft_read_file(path)) != crc32)
	{
		ft_fprintf(STDERR,
			RED2"Error : "INDIANRED2"Unable to verify integrity of : %s%s\n"
			GREEN2"FIX : %sRestore the original file.\n%s",
			ORANGE2, path, YELLOW, RESET);
		clean_exit_mlx(1, game);
	}
}

t_sprite	ft_load_sprite(t_game *game, char *path, unsigned int crc32)
{
	t_sprite	sprite;
	int			size;
	char		*content;

	if (!ft_exists(path))
		ft_load_fail(game, path);
	size = 64;
	sprite.path = path;
	sprite.crc32 = crc32;
	sprite.image = mlx_xpm_file_to_image(game->mlx_ptr, path, &size, &size);
	if (sprite.image == NULL)
	{
		mlx_destroy_image(game->mlx_ptr, sprite.image);
		ft_load_fail(game, path);
	}
	check_integrity(game, path, crc32);
	game->sprites_init++;
	return (sprite);
}

void	ft_load_sprite_table(t_game *game, t_table table, int i)
{
	t_sprite	sprite;

	sprite = ft_load_sprite(game, table.xpm_path, table.crc32);
	game->sprites[i] = sprite;
}

void	ft_load_sprite_table_file(t_game *game, char *path, unsigned int crc32)
{
	t_chain_lst	*lines;
	t_chain_lst	*tmp;
	t_table		t;

	game->sprites_init = 0;
	lines = ft_read_table(game, path, crc32);
	tmp = lines;
	while (tmp)
	{
		if (tmp->content)
		{
			t = ft_parse_line(game, tmp);
			ft_load_sprite_table(game, t, game->sprites_init);
		}
		tmp = tmp->next;
	}
}
