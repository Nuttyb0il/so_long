/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:08:43 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/27 16:34:39 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/memory.h"
#include "../libft/includes/colors.h"
#include "../libft/includes/printf.h"
#include "../libft/includes/lists.h"
#include "../includes/mlx.h"
#include "../includes/so_long.h"
#include <unistd.h>

// clean exit but when MLX is initialized
void	clean_exit_mlx(int code, t_game *game)
{
	int		i;

	i = 0;
	while (i < game->sprites_init)
	{
		if (game->sprites[i].image)
			mlx_destroy_image(game->mlx_ptr, game->sprites[i].image);
		i++;
	}
	if (game->mlx_ptr)
		mlx_loop_end(game->mlx_ptr);
	else
		clean_exit(code);
	if (game->game_window)
		mlx_destroy_window(game->mlx_ptr, game->game_window);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	clean_exit(code);
}

void	clean_exit(int code)
{
	ft_full_free();
	exit(code);
}
