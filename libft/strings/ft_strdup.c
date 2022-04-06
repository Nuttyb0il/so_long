/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:47:50 by jallerha          #+#    #+#             */
/*   Updated: 2022/02/26 15:33:54 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/string.h"
#include "../includes/memory.h"

char	*ft_strdup(char *s)
{
	char	*output;

	if (!ft_malloc(&output, sizeof(char), ft_strlen(s) + 1))
		return (NULL);
	ft_strcpy(output, s);
	return (output);
}
