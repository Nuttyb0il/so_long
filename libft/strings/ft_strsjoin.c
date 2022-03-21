/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:52:49 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/19 15:31:58 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/string.h"
#include "../includes/memory.h"

char	*ft_strsjoin(char *s1, char *s2)
{
	int		len_s1;
	int		len_s2;
	char	*output;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!ft_malloc(&output, sizeof(char), len_s1 + len_s2 + 1))
		return (NULL);
	ft_strcpy(output, s1);
	ft_strcpy(output + len_s1, s2);
	return (output);
}
