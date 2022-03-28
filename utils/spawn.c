/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 00:52:24 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/27 16:23:59 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/printf.h"
#include "../libft/includes/string.h"

void	ft_random_spawn(t_map *map)
{
	int	random_spawn;
	int	i;
	int	j;

	i = 0;
	j = 0;
	random_spawn = ft_pseudo_random(0, ft_count_words(map->map, "P"));
	while (map->map[i])
	{
		if (map->map[i] == 'P' && j != random_spawn)
		{
			map->map[i] = '0';
			j++;
		}
		else if (map->map[i] == 'P' && j == random_spawn)
			j++;
		i++;
	}
}
