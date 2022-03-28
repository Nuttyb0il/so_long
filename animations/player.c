/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:01:14 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/27 17:01:21 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_set_animation(t_game *game)
{
	static int	offset = 0;

	if (game->game_clock == ANIMATION_DELAY)
	{
		offset++;
		game->game_clock = 0;
	}
	if (offset == 4)
		offset = 0;
	if (game->direction == RIGHT)
		game->player_image = game->sprites[offset + 14].image;
	else if (game->direction == LEFT)
		game->player_image = game->sprites[offset + 10].image;
	else if (game->direction == UP)
		game->player_image = game->sprites[offset + 2].image;
	else if (game->direction == DOWN)
		game->player_image = game->sprites[offset + 6].image;
}
