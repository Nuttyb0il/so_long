/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:14:41 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/01 22:27:10 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lists.h"
#include "../includes/string.h"
#include "../includes/memory.h"

void	ft_concat(char *dest, char *src)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!dest || !src)
		return ;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
}

int	ft_get_size(t_chain_lst *lst)
{
	int			size;
	t_chain_lst	*tmp;

	size = 0;
	tmp = lst;
	while (tmp)
	{
		if (tmp->content)
			size += ft_strlen(tmp->content);
		tmp = tmp->next;
	}
	return (size);
}

char	*ft_strjoin(char *separator, t_chain_lst *iterable)
{
	char		*output;
	int			size;
	t_chain_lst	*tmp;

	size = ft_get_size(iterable) + (ft_strlen(separator)
			* (ft_chain_count(iterable)));
	if (!ft_malloc(&output, sizeof(char), size + 1))
		return (NULL);
	ft_bzero(output, size + 1);
	tmp = iterable;
	while (tmp)
	{
		if (tmp->content)
		{
			ft_concat(output, (char *) tmp->content);
			if (tmp->next)
				ft_concat(output, separator);
		}
		tmp = tmp->next;
	}
	output[size] = '\0';
	return (output);
}
