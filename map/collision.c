/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:15:39 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/23 20:17:06 by jallerha         ###   ########.fr       */
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
			ft_render_sprite_by_id(game, 0, x * 64, y * 64);
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

int	ft_legal_move(int direction, t_game *game)
{
	char	tile;
	int		x;
	int		y;

	x = game->x / 64;
	y = game->y / 64;
	if (direction == UP)
		y--;
	else if (direction == DOWN)
		y++;
	else if (direction == LEFT)
		x--;
	else if (direction == RIGHT)
		x++;
	tile = ft_get_tile_at(game, x, y);
	if (tile == 'C')
	{
		game->map_data.collectibles--;
		game->map_data.flat[y * game->map_data.width + x] = '0';
		if (game->map_data.collectibles == 0)
			ft_refresh_exits(game);
	}
	else if (tile == 'E' && game->map_data.collectibles <= 0)
		clean_exit_mlx(0, game);
	return (tile != '1');
}