/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 23:56:18 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/27 16:33:41 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_register_berry_animation(t_game *game, int x, int y)
{
	t_animation	animation;

	animation.x = x;
	animation.y = y;
	animation.frame_count = 4;
	animation.frame = ft_pseudo_random(0, 5);
	animation.clock = ft_pseudo_random(-255, 255);
	animation.base_offset = 28;
	animation.baf_mode = 1;
	animation.baf_direction = 0;
	animation.stop = 0;
	animation.obj_type = BERRY_ANIMATION_ID;
	game->animations[game->anim_inits] = animation;
	game->anim_inits++;
}

void	ft_register_seed_animation(t_game *game, int x, int y)
{
	t_animation	animation;

	animation.x = x;
	animation.y = y;
	animation.frame_count = 4;
	animation.frame = ft_pseudo_random(0, 5);
	animation.clock = ft_pseudo_random(-255, 255);
	animation.base_offset = 18;
	animation.baf_mode = 1;
	animation.baf_direction = 0;
	animation.stop = 0;
	animation.obj_type = SEED_ANIMATION_ID;
	game->animations[game->anim_inits] = animation;
	game->anim_inits++;
}
