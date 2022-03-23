/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integrity.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:03:57 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/23 13:09:30 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
