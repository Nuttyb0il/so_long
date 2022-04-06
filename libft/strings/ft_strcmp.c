/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:56:49 by jallerha          #+#    #+#             */
/*   Updated: 2022/02/26 15:43:18 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/string.h"
#include "../includes/chartype.h"
#include "../includes/conversions.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
		i++;
	return (s1[i] - s2[i]);
}

int	ft_strcmpi(char *s1, char *s2)
{
	int		i;
	char	c1;
	char	c2;

	i = 0;
	while (s1[i] && s2[i])
	{
		c1 = s1[i];
		c2 = s2[i];
		if (ft_isalpha(c1) && ft_isalpha(c2)
			&& ft_toupper(c1) != ft_toupper(c2))
			c1 = ft_toupper(c1);
		if (c1 != c2)
			return (c1 - c2);
		i++;
	}
	return (0);
}
