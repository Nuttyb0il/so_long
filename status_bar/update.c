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

void	ft_update_movements(t_game *game)
{
	int	n_size;

	n_size = int_size(game->moves);
	ft_render_sprite_by_id(game, 48, 0, game->win_height - game->size);
	ft_render_sprite_by_id(game, 46,
		game->size, game->win_height - (game->size / 1.5));
	if (game->moves >= 0 && int_size(game->moves) + 2
		< game->win_width / game->size)
		ft_render_number(game, game->moves, game->size * 1.5);
	else
	{
		ft_render_sprite_by_id(game, 49, game->size * 1.5,
			game->win_height - game->size);
		ft_printf(ORANGE2"Moves : %s%d%s\n", RED3, game->moves, RESET);
	}
}

void	ft_refresh_status(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_data.width)
	{
		ft_render_sprite_by_id(game, 33, i * game->size,
			game->win_height - game->size);
		i++;
	}
	ft_update_movements(game);
}
