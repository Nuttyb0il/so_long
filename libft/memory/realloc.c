/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:10:07 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/21 11:36:43 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/memory.h"
#include "../includes/string.h"

void	*ft_realloc(void *ptr, size_t new_size)
{
	void	*new_ptr;

	if (!ptr)
		return (NULL);
	if (!ft_malloc(&new_ptr, 1, new_size))
		return (NULL);
	ft_memcpy(new_ptr, ptr, new_size);
	ft_free(&ptr);
	return (new_ptr);
}
