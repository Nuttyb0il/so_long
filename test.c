/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:45:42 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/21 15:14:43 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/colors.h"
#include "libft/includes/printf.h"
#include "libft/includes/constants.h"
#include "includes/so_long.h"
#include <stdlib.h> // SYSTEM

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc == 2)
	{
		map = ft_load_map(argv[1]);
		ft_printf(YELLOW"Width : %d\n"RESET, map.width);
		ft_printf(YELLOW"Height : %d\n"RESET, map.height);
		ft_printf(YELLOW"Collectibles : %d\n"RESET, map.collectibles);
		ft_printf(YELLOW"Spawns : %d\n"RESET, map.spawns);
		ft_printf(YELLOW"Exits : %d\n"RESET, map.exits);
		if (map.sanity)
			ft_printf(GREEN2"Sanity : OK!\n"RESET);
		else
			ft_printf(RED2"Sanity : KO!\n"RESET);
		ft_printf(BLUEVIOLET"Map :\n"RESET);
		ft_printf(BLUEVIOLET"%s"RESET, map.map);
		clean_exit(0);
	}
	else
	{
		ft_fprintf(STDERR,
			PURPLE1"Usage: %s%s%s <map>\n%sExample :\n\t%s%s%s maps/map_01.ber%s",
			HOTPINK4, argv[0], YELLOW, PURPLE1, HOTPINK4, argv[0], YELLOW, RESET
			);
		clean_exit(ERROR);
	}
	clean_exit(0);
}
