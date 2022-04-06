/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:12:16 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/27 16:24:06 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/file.h"
#include "../libft/includes/memory.h"
#include "../libft/includes/printf.h"

int	ft_pseudo_random(int min, int max)
{
	int		c;
	int		fd;

	c = 0;
	fd = open("/dev/urandom", O_RDONLY);
	if (fd < 0)
		fd = open("/dev/random", O_RDONLY);
	if (fd < 0)
		return (min);
	read(fd, &c, 1);
	close(fd);
	return (min + (c % (max - min)));
}
