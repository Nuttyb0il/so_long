/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:57:51 by jallerha          #+#    #+#             */
/*   Updated: 2022/02/22 16:12:13 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/memory.h"

static int	ft_nlength(int nbr)
{
	int	len;

	len = 1;
	if (nbr == 0)
		return (2);
	if (nbr < 0)
	{
		nbr = -nbr;
		len++;
	}
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	nbr;
	int			length;

	nbr = n;
	length = ft_nlength(nbr);
	ft_malloc(&str, sizeof(char), length);
	if (!str)
		return (0);
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	if (nbr == 0)
		str[0] = '0';
	str[--length] = '\0';
	while (nbr)
	{
		str[length - 1] = nbr % 10 + '0';
		nbr /= 10;
		length--;
	}
	return (str);
}
