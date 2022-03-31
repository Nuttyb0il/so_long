/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:15:39 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/31 14:01:01 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/mlx.h"
#include "../libft/includes/bool.h"
#include "../libft/includes/printf.h"
#include "../libft/includes/lists.h"

void	ft_refresh_exits(t_game *game)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = -1;
	y = 0;
	while (game->map_data.map[i])
	{
		if (game->map_data.map[i] == 'E')
			ft_change_berries(game);
		else if (game->map_data.map[i] == '\n')
		{
			x = -1;
			y++;
		}
		i++;
		x++;
	}
}

char	ft_get_tile_at(t_game *game, int x, int y)
{
	return (game->map_data.flat[y * game->map_data.width + x]);
}

void	ft_compute_move(int direction, int *x, int *y)
{
	if (direction == UP)
		(*y)--;
	else if (direction == DOWN)
		(*y)++;
	else if (direction == LEFT)
		(*x)--;
	else if (direction == RIGHT)
		(*x)++;
}

int	ft_legal_move(int direction, t_game *game)
{
	char	tile;
	int		x;
	int		y;

	x = game->x / game->size;
	y = game->y / game->size;
	ft_compute_move(direction, &x, &y);
	tile = ft_get_tile_at(game, x, y);
	if (tile == 'C')
	{
		game->map_data.collectibles--;
		game->map_data.flat[y * game->map_data.width + x] = '0';
		ft_stop_animation(game, x * game->size, y * game->size);
		if (game->map_data.collectibles == 0)
			ft_refresh_exits(game);
	}
	else if (tile == 'E' && game->map_data.collectibles <= 0)
		ft_clean_exit_mlx(0, game);
	return (tile != '1');
}
