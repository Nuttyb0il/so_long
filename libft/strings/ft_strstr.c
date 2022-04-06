/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:45:34 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/01 14:25:16 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/string.h"

char	*ft_strstr(char *needle, char *haystack)
{
	int	i;
	int	j;
	int	haystack_len;
	int	needle_len;

	i = 0;
	j = 0;
	haystack_len = ft_strlen(haystack);
	needle_len = ft_strlen(needle);
	while (i < haystack_len)
	{
		if (needle[j] == haystack[i])
		{
			j++;
			i++;
		}
		else
		{
			i = i - j;
			j = 0;
		}
		if (j == needle_len)
			return (haystack + i - j);
	}
	return (NULL);
}

char	*ft_strrstr(char *needle, char *haystack)
{
	int	i;
	int	j;
	int	needle_len;

	i = ft_strlen(haystack);
	j = ft_strlen(needle);
	needle_len = j;
	while (i >= 0)
	{
		if (needle[j] == haystack[i])
		{
			j--;
			i--;
		}
		else
		{
			i = i + needle_len - j - 1;
			j = needle_len - 1;
		}
		if (j == -1)
			return (haystack + i + 1);
	}
	return (NULL);
}
