/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 23:42:46 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/31 14:01:01 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/string.h"
#include "../libft/includes/memory.h"
#include "../includes/so_long.h"

void	ft_init_animations(t_game *game)
{
	game->animated_objects = game->map_data.collectibles + game->map_data.exits;
	game->anim_inits = 0;
	if (!ft_malloc(&game->animations, sizeof(t_animation),
			game->animated_objects))
		ft_clean_exit_mlx(1, game);
	ft_bzero(game->animations, sizeof(t_animation) * game->animated_objects);
}
