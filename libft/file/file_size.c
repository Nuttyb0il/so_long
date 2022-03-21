/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:19:40 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/21 11:34:48 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file.h"

int	ft_file_size(int fd)
{
	int		ret;
	int		size;
	char	buffer[BUFFER_SIZE + 1];

	size = 0;
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		size += ret;
	}
	close(fd);
	return (size);
}
