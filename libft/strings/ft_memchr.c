/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:55:15 by jallerha          #+#    #+#             */
/*   Updated: 2022/02/23 12:07:52 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/string.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}

void	*ft_memrchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = n;
	while (i > 0)
	{
		if (((unsigned char *)s)[i - 1] == (unsigned char)c)
			return ((void *)s + i - 1);
		i--;
	}
	return (NULL);
}
