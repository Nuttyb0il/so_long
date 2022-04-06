/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 23:37:53 by jallerha          #+#    #+#             */
/*   Updated: 2022/04/06 14:17:30 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/printf.h"
#include "../libft/includes/colors.h"

int	int_size(int n)
{
	int	c;

	if (n <= 0)
		return (1);
	c = 0;
	while (n > 0)
	{
		n /= 10;
		c++;
	}
	return (c);
}

void	ft_update_collectibles(t_game *game)
{
	ft_render_sprite_by_id(game, 45, 8, game->win_height - game->size);
	ft_render_sprite_by_id(game, 47, 64, game->win_height - game->size);
	ft_render_number(game, game->map_data.collectibles, 128);
}

void	ft_update_movements(t_game *game, int collectibles_hidden)
{
	int	n_size;
	int	x_offset;

	n_size = int_size(game->moves);
	x_offset = 0;
	if (collectibles_hidden)
		x_offset = game->win_width - (8 + game->size * (n_size + 1));
	ft_render_sprite_by_id(game, 48, x_offset, game->win_height - game->size);
	x_offset += game->size;
	ft_render_sprite_by_id(game, 46,
		x_offset, game->win_height - (game->size / 1.5));
	x_offset += game->size - (game->size / 1.5);
	if ((n_size + 1 + int_size(game->map_data.collectibles))
		> (game->win_width / game->size) + 1 || game->moves < 0)
	{
		ft_render_sprite_by_id(game, 49, x_offset - (game->size / 3),
			game->win_height - game->size);
		ft_printf(ORANGE2"Moves : %s%d%s\n", RED3, game->moves, RESET);
	}
	else
		ft_render_number(game, game->moves, x_offset);
}

void	ft_refresh_status(t_game *game)
{
	int	i;
	int	hide_collectibles;

	i = 0;
	while (i < game->map_data.width)
	{
		ft_render_sprite_by_id(game, 33, i * game->size,
			game->win_height - game->size);
		i++;
	}
	hide_collectibles = (game->win_width / game->size) > 6;
	if (hide_collectibles)
		ft_update_collectibles(game);
	ft_update_movements(game, hide_collectibles);
}
