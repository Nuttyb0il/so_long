/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fail.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:16:58 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/29 16:17:46 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/printf.h"
#include "../libft/includes/colors.h"
#include "../libft/includes/constants.h"

void	ft_map_read_fail(t_game *game, char *path)
{
	ft_fprintf(STDERR,
		RED2"Error: "INDIANRED1"'%s'"ORANGE2" is not a map file\n"RESET, path
		);
	clean_exit(ERROR);
}