/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 23:51:30 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/29 17:42:12 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/mlx.h"
#include "../libft/includes/printf.h"

void	ft_change_berries(t_game *game)
{
	t_animation	anim;
	int			i;

	i = 0;
	while (i < game->animated_objects)
	{
		if (game->animations[i].obj_type == BERRY_ANIMATION_ID)
		{
			game->animations[i].obj_type = -1;
			game->animations[i].base_offset -= 5;
		}
		i++;
	}
}

void	ft_render_animations(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->anim_inits)
	{
		ft_render_animation(game, &game->animations[i]);
		i++;
	}
}

void	ft_refresh_baf(t_animation *animation)
{
	if (animation->baf_mode == 1)
	{
		if (animation->baf_direction == 0)
		{
			if (animation->frame == 0)
				animation->baf_direction = 1;
			else
				animation->frame--;
		}
		else
		{
			if (animation->frame == animation->frame_count)
				animation->baf_direction = 0;
			else
				animation->frame++;
		}
	}
}

void	ft_render_animation(t_game *game, t_animation *animation)
{
	if (animation->stop)
		return ;
	if (animation->baf_mode && animation->frame > animation->frame_count)
	{
		animation->frame = 0;
		animation->baf_direction = !animation->baf_direction;
	}
	else if (!animation->baf_mode && animation->frame > animation->frame_count)
		animation->frame = 0;
	if (animation->clock >= ANIMATION_DELAY / 1.6)
	{
		ft_refresh_baf(animation);
		animation->clock = 0;
		mlx_put_image_to_window(game->mlx_ptr, game->game_window,
			game->sprites[animation->base_offset + animation->frame].image,
			animation->x, animation->y);
	}
}
