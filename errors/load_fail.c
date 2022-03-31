/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_fail.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:49:12 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/31 14:01:01 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/printf.h"
#include "../libft/includes/colors.h"
#include "../libft/includes/bool.h"
#include "../libft/includes/constants.h"
#include "../libft/includes/string.h"

int	ft_exists(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (FALSE);
	close(fd);
	return (TRUE);
}

void	ft_load_fail(t_game *game, char *path)
{
	if (ft_endswith(path, ".xpm"))
		ft_fprintf(STDERR,
			RED2"Error : "INDIANRED2"Failed to load sprite : %s%s\n",
			ORANGE2, path);
	else if (ft_endswith(path, ".tbl"))
		ft_fprintf(STDERR,
			RED2"Error : "INDIANRED2"Failed to load sprite table : %s%s\n",
			ORANGE2, path);
	else
		ft_fprintf(STDERR,
			RED2"Error : "INDIANRED2"Failed to load : %s%s\n",
			ORANGE2, path);
	ft_clean_exit_mlx(1, game);
}

void	ft_integrity_table_fail(t_game *game, char *path)
{
	ft_fprintf(STDERR,
		RED2"Error : "INDIANRED2"Sprite table : %s%s%s has been altered.\n%s",
		ORANGE2, path, INDIANRED2, RESET);
	ft_clean_exit_mlx(1, game);
}
