/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 23:08:15 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/01 14:23:12 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/string.h"
#include "../includes/memory.h"

char	*ft_replace(char *str, char *old, char *new)
{
	char	*output;
	int		found;
	int		next_sep;
	int		new_size;

	found = ft_count_words(str, old);
	new_size = ft_strlen(str) - (ft_strlen(old) * found)
		+ (ft_strlen(new) * found) + 1;
	if (new_size == 0)
		return (ft_strdup(""));
	next_sep = ft_index(str, old);
	if (!ft_malloc(&output, sizeof(char), new_size))
		return (NULL);
	while (next_sep != -1)
	{
		ft_strncpy(output, str, next_sep);
		str += next_sep + ft_strlen(old);
		ft_strcat(output, new);
		next_sep = ft_index(str, old);
	}
	ft_strcat(output, str);
	return (output);
}
