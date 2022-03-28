/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_n_bytes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:34:42 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/25 15:15:26 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "../includes/string.h"
#include "../includes/memory.h"

unsigned char	*read_n_bytes(char *path, size_t n)
{
	unsigned char	*buffer;
	int				fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	if (!ft_malloc(&buffer, sizeof(unsigned char), n))
		return (NULL);
	if (read(fd, buffer, n) < 0)
		return (NULL);
	close(fd);
	return (buffer);
}
