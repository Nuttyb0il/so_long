/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 19:32:03 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/01 13:59:02 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/string.h"
#include "../includes/memory.h"

char	*ft_strcpyr(char *src, int start, int end)
{
	char	*dest;
	int		i;

	i = 0;
	if (!ft_malloc(&dest, sizeof(char), end - start + 1))
		return (NULL);
	while (start < end)
	{
		dest[i] = src[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}

t_chain_lst	*ft_split(char *str, char *word)
{
	t_chain_lst	*output;
	int			start;
	int			end;
	int			sep_len;

	output = ft_chain_init();
	sep_len = ft_strlen(word);
	start = 0;
	end = ft_index(str, word);
	while (end != -1)
	{
		ft_chain_append(&output, ft_strcpyr(str, start, end));
		str += end + sep_len;
		end = ft_index(str, word);
	}
	ft_chain_append(&output, ft_strdup(str));
	return (output);
}
