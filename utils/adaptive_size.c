/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:17:08 by jallerha          #+#    #+#             */
/*   Updated: 2022/04/06 01:22:43 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/printf.h"

int	ft_table_size(t_game *game)
{
	if (game->map_data.height <= 21 && game->map_data.width <= 41)
		return (64);
	else if ((game->map_data.height >= 22 && game->map_data.height <= 28)
		|| (game->map_data.width >= 42 && game->map_data.width <= 54))
		return (48);
	else if ((game->map_data.height > 28 && game->map_data.height <= 42)
		|| (game->map_data.width >= 55 && game->map_data.width <= 81))
		return (32);
	else
		return (-1);
}
