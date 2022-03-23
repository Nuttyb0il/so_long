/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crc32.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:15:17 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/23 13:09:06 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/includes/printf.h"
#include "../../libft/includes/string.h"
#include "../../libft/includes/colors.h"
#include "../../libft/includes/file.h"

unsigned int	ft_crc32b(char *message)
{
	int				i;
	int				j;
	unsigned int	byte;
	unsigned int	crc;
	unsigned int	mask;

	i = 0;
	crc = 0xFFFFFFFF;
	while (message[i] != 0)
	{
		j = 7;
		byte = message[i];
		crc = crc ^ byte;
		while (j >= 0)
		{
			mask = -(crc & 1);
			crc = (crc >> 1) ^ (0xEDB88320 & mask);
			j--;
		}
		i++;
	}
	return (~crc);
}

int	main(int argc, char **argv)
{
	char *content;

	if (argc <= 1)
	{
		ft_printf("%sPlease enter file names.%s\n", RED, RESET);
		return (1);
	}
	for (size_t i = 0; i < argc; i++)
	{
		if (ft_endswith(argv[i], ".xpm"))
		{
			// content = ft_read_file(argv[i]);
			// convert ft_read_file to unsigned char *
			content = (char *)ft_read_file(argv[i]);
			ft_printf(YELLOW1"%s -- %s%x%s\n", argv[i], GREEN1, ft_crc32b(content), RESET);
		}
	}
	return (0);
}