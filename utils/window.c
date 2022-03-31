/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:21:08 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/31 14:38:21 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/mlx.h"
#include "../libft/includes/printf.h"
#include "../libft/includes/colors.h"
#include "../libft/includes/put.h"
#include "../libft/includes/constants.h"

void	ft_confirm(t_game *game)
{
	char	choice[1];
	ft_putendl_fd(
		RED2"You're about to load a map that's bigger than the screen.",
		STDERR);
	ft_putstr_fd(
		ORANGE2"Are you sure you want to continue? (y/n) ", STDERR);
	read(STDIN, choice, 1);
	if (choice[0] == 'N' || choice[0] == 'n')
		ft_clean_exit_mlx(1, game);
}

void	ft_create_window(t_game *game)
{
	int	width;
	int	height;

	width = game->map_data.width * game->size;
	height = game->map_data.height * game->size;
	game->game_window = mlx_new_window(game->mlx_ptr, width, height, "so_long");
	if (!game->game_window)
		ft_clean_exit_mlx(1, game);
}