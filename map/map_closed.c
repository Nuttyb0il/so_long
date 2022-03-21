/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_closed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:36:34 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/21 14:13:42 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/string.h"
#include "../libft/includes/bool.h"
#include "../libft/includes/lists.h"

int	ft_is_wall(void *s)
{
	char	*str;

	str = (char *)s;
	return (ft_strlen(s) == ft_count_words(s, "1"));
}

int	ft_wall_at_ends(void *s)
{
	char	*str;

	str = (char *)s;
	return (ft_startswith(str, "1") && ft_endswith(str, "1"));
}

int	ft_valid(int i, int line_count, void *content, t_chain_lst *lines)
{
	char	*str;

	str = (char *)content;
	if ((i == 0 || i == line_count) && !(ft_is_wall(str)))
	{
		ft_chain_clear(&lines);
		return (FALSE);
	}
	else if (i != 0 && i != line_count && !(ft_wall_at_ends(str)))
	{
		ft_chain_clear(&lines);
		return (FALSE);
	}
	return (TRUE);
}

int	ft_map_closed(char *s)
{
	t_chain_lst	*lines;
	t_chain_lst	*tmp;
	int			i;
	int			line_count;

	lines = ft_split(s, "\n");
	line_count = ft_count_words(s, "\n");
	tmp = lines;
	i = 0;
	while (tmp)
	{
		if (!ft_valid(i, line_count, tmp->content, lines))
			return (FALSE);
		tmp = tmp->next;
		i++;
	}
	ft_chain_clear(&lines);
	return (TRUE);
}
