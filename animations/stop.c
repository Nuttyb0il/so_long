/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 00:42:43 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/27 16:33:45 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_stop_animation(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	while (i < game->anim_inits)
	{
		if (game->animations[i].x == x && game->animations[i].y == y)
		{
			game->animations[i].stop = 1;
			return ;
		}
		i++;
	}
}
