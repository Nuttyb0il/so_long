/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_closed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:36:34 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/27 16:25:16 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/string.h"
#include "../libft/includes/bool.h"
#include "../libft/includes/lists.h"
#include "../libft/includes/printf.h" // todo: remove

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
	if ((i == 0 || i == line_count - 1) && !(ft_is_wall(str)))
		return (FALSE);
	else if (i != 0 && i != line_count && !(ft_wall_at_ends(str)))
		return (FALSE);
	return (TRUE);
}

int	ft_map_closed(t_chain_lst *lines)
{
	t_chain_lst	*tmp;
	int			i;
	int			line_count;

	line_count = ft_chain_count(lines);
	tmp = lines;
	i = 0;
	while (tmp)
	{
		if (!ft_valid(i, line_count, tmp->content, lines)
			|| ft_strlen(tmp->content) <= 1)
			return (FALSE);
		tmp = tmp->next;
		i++;
	}
	return (TRUE);
}
