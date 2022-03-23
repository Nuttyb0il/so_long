/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:46:57 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/23 14:26:50 by jallerha         ###   ########.fr       */
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
	t_sprite sprite;
	int		size;
	char	*content;

	check_integrity(game, path, crc32);
	size = 64;
	sprite.path = path;
	sprite.crc32 = crc32;
	sprite.image = mlx_xpm_file_to_image(game->mlx_ptr, path, &size, &size);
	if (sprite.image == NULL)
	{
		ft_fprintf(STDERR,
			RED2"Error : "INDIANRED2"Failed to load sprite %s%s%s\n",
			ORANGE2, path, RESET);
		mlx_destroy_image(game->mlx_ptr, sprite.image);
		clean_exit_mlx(1, game);
	}
	game->sprites_init++;
	return (sprite);
}

void	ft_load_sprites(t_game *game)
{
	game->sprites_init = 0;
	if (!ft_malloc(&game->sprites, sizeof(t_sprite), SPRITE_COUNT))
		clean_exit_mlx(1, game);
	game->sprites[0] = ft_load_sprite(game, "assets/berry.xpm", 0xf8bdd8ae);
	game->sprites[1] = ft_load_sprite(game, "assets/gberry.xpm", 0xc929024f);
	game->sprites[2] = ft_load_sprite(game, "assets/ice.xpm", 0x8777344c);
	game->sprites[3] = ft_load_sprite(game, "assets/pb1.xpm", 0xfc7fc336);
	game->sprites[4] = ft_load_sprite(game, "assets/pb2.xpm", 0x56b05c7f);
	game->sprites[5] = ft_load_sprite(game, "assets/pb3.xpm", 0xe6e0866c);
	game->sprites[6] = ft_load_sprite(game, "assets/pb4.xpm", 0x2cbdd1ef);
	game->sprites[7] = ft_load_sprite(game, "assets/pf1.xpm", 0x48e43f10);
	game->sprites[8] = ft_load_sprite(game, "assets/pf2.xpm", 0xcf1d7807);
	game->sprites[9] = ft_load_sprite(game, "assets/pf3.xpm", 0xd82b9154);
	game->sprites[10] = ft_load_sprite(game, "assets/pf4.xpm", 0x4bb1901);
	game->sprites[11] = ft_load_sprite(game, "assets/pl1.xpm", 0x19ceee10);
	game->sprites[12] = ft_load_sprite(game, "assets/pl2.xpm", 0xe7984dd8);
	game->sprites[13] = ft_load_sprite(game, "assets/pl3.xpm", 0x830086fa);
	game->sprites[14] = ft_load_sprite(game, "assets/pl4.xpm", 0x810e9e58);
	game->sprites[15] = ft_load_sprite(game, "assets/pr1.xpm", 0xdd1283ed);
	game->sprites[16] = ft_load_sprite(game, "assets/pr2.xpm", 0x8c5d69f6);
	game->sprites[17] = ft_load_sprite(game, "assets/pr3.xpm", 0xdcd468ff);
	game->sprites[18] = ft_load_sprite(game, "assets/pr4.xpm", 0xc7b7ed95);
	game->sprites[19] = ft_load_sprite(game, "assets/seed.xpm", 0xb3dec10a);
	game->sprites[20] = ft_load_sprite(game, "assets/wall.xpm", 0xd79fb7);
}