/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:02:30 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/31 15:22:58 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/mlx.h"

void	ft_init_status(t_game *game)
{
	int	horizontal_tiles;

	horizontal_tiles = game->map_data.width;
	while (horizontal_tiles > 0)
	{
		ft_render_sprite_by_id(game, 33, horizontal_tiles * game->size,
					game->window_height - game->size);
		horizontal_tiles--;
	}
}