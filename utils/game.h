/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:23:29 by jallerha          #+#    #+#             */
/*   Updated: 2022/02/02 17:24:26 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "../so_long.h"

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_sprite	*sprites;
	t_map		*map;
	int			sprite_count;
	int			window_width;
	int			window_height;
}	t_game;

t_game	ft_load_game(char **sprites_path, char **sprites_name,
			char *map_path, int sprite_count);
void	ft_init_game(t_game *game, int sprite_count);
#endif