/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:08:58 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/21 11:34:59 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/string.h"
#include "../includes/memory.h"
#include "../includes/file.h"
#include <stdio.h>

char	*ft_read_file(char *path)
{
	int		size;
	int		fd;
	char	*buffer;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	size = ft_file_size(fd);
	if (size == 0)
		return (ft_strdup(""));
	fd = open(path, O_RDONLY);
	if (!ft_malloc(&buffer, sizeof(char), size + 1))
		return (NULL);
	read(fd, buffer, size);
	buffer[size] = '\0';
	close(fd);
	return (buffer);
}
