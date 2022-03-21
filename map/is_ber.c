/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ber.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:25:17 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/21 14:30:56 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/file.h"
#include "../libft/includes/string.h"
#include "../includes/so_long.h"

int	ft_is_ber(char *path)
{
	char	buffer[32];
	int		fd;
	int		i;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	if (read(fd, buffer, 2) == -1)
		return (0);
	while (buffer[i])
	{
		if (!ft_is_valid_char(buffer[i]))
			return (0);
		i++;
	}
	close(fd);
	return (1);
}
