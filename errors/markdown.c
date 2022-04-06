/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markdown.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:31:02 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/31 14:01:01 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/printf.h"
#include "../libft/includes/constants.h"
#include "../libft/includes/colors.h"
#include <unistd.h>

int	ft_is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P'
		|| c == '\n');
}

char	*ft_get_error(int code)
{
	if (code == INVALID_COLLECTIBLES)
		return ("No collectibles were placed on the map");
	else if (code == INVALID_SPAWNS)
		return ("No spawns were placed on the map");
	else if (code == INVALID_EXITS)
		return ("No exits were placed on the map");
	else if (code == INVALID_MAP_CHARACTERS)
		return ("Unrecognized characters were found in the map");
	else if (code == INVALID_LINE_LENGTH)
		return ("Map is not rectangular (check carefully each line's length)");
	else if (code == MAP_NOT_CLOSED)
		return ("The map isn't properly surrounded by walls");
	else
		return (GREY35"Unknown error");
}

void	ft_print_char(int code, char c)
{
	if (code == INVALID_MAP_CHARACTERS && !ft_is_valid_char(c))
		ft_fprintf(STDERR, "%s%c%s", RED2, c, RESET);
	else if (code == INVALID_MAP_CHARACTERS && ft_is_valid_char(c))
		ft_fprintf(STDERR, "%s%c%s", GREEN2, c, RESET);
	else if (code == MAP_NOT_CLOSED && c == '1')
		ft_fprintf(STDERR, "%s%c%s", YELLOW, c, RESET);
	else if (code == MAP_NOT_CLOSED && c != '1')
		ft_fprintf(STDERR, "%s%c%s", GREEN2, c, RESET);
	else if (code == INVALID_LINE_LENGTH && c != '1')
		ft_fprintf(STDERR, "%s%c%s", GREEN2, c, RESET);
	else if (code == INVALID_LINE_LENGTH && c == '1')
		ft_fprintf(STDERR, "%s%c%s", YELLOW, c, RESET);
	else if (code == INVALID_COLLECTIBLES && c == 'C')
		ft_fprintf(STDERR, "%s%c%s", RED2, c, RESET);
	else if (code == INVALID_SPAWNS && c == 'S')
		ft_fprintf(STDERR, "%s%c%s", RED2, c, RESET);
	else if (code == INVALID_EXITS && c == 'E')
		ft_fprintf(STDERR, "%s%c%s", RED2, c, RESET);
	else
		ft_fprintf(STDERR, "%s%c%s", GREEN2, c, RESET);
}

void	ft_print_error(int code)
{
	ft_fprintf(STDERR,
		RED2"Parsing Error: "ORANGE2"%s\n"RESET, ft_get_error(code)
		);
}

void	ft_print_markdown(int code, t_map *map)
{
	int		i;

	i = 0;
	ft_print_error(code);
	ft_fprintf(STDERR, ""INDIANRED2"Map: \n"RESET);
	while (i < map->length)
	{
		ft_print_char(code, map->map[i]);
		i++;
	}
	ft_fprintf(STDERR, RESET"\nColor legend :\n");
	ft_fprintf(STDERR,
		RED2"  █"RESET"  Invalid character\n"
		);
	ft_fprintf(STDERR,
		YELLOW"  █"RESET"  Possible invalid wall\n"
		);
	ft_fprintf(STDERR,
		GREEN2"  █"RESET"  Valid character surrounded by walls"
		);
	ft_clean_exit(code);
}
