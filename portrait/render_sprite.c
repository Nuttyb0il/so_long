/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:17:57 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/27 16:59:14 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/mlx.h"
#include "../libft/includes/printf.h"
#include "../libft/includes/colors.h"
#include "../libft/includes/constants.h"
#include "../libft/includes/lists.h"

void	ft_render_sprite_by_id(t_game *game, int id, int x, int y)
{
	void		*image;

	image = game->sprites[id].image;
	if (image != NULL)
		mlx_put_image_to_window(game->mlx_ptr, game->game_window, image, x, y);
	else
	{
		ft_fprintf(STDERR,
			RED2"Error : "INDIANRED2"Failed to render sprite %s#%d%s\n",
			ORANGE2, id, RESET);
		clean_exit_mlx(1, game);
	}
}
