/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:42:44 by jallerha          #+#    #+#             */
/*   Updated: 2022/02/23 13:36:58 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/memory.h"
#include "../includes/constants.h"

static inline t_alloc_lst	**singleton(void)
{
	static t_alloc_lst	*lst = NULL;

	return (&lst);
}

int	ft_malloc(void *ptr, const size_t type_size, const size_t size)
{
	t_alloc_lst	*lst;

	*(void **)ptr = NULL;
	lst = (t_alloc_lst *)malloc(sizeof(t_alloc_lst));
	if (!lst || type_size <= 0 || size <= 0)
		return (ERROR);
	lst->ptr = malloc(type_size * size);
	if (!lst->ptr)
		return (free(lst), ERROR);
	lst->next = *(singleton());
	*(void **)ptr = lst->ptr;
	*(singleton()) = lst;
	return (SUCCESS);
}

int	ft_free(void *ptr)
{
	t_alloc_lst	*lst;
	t_alloc_lst	*prev;

	if (!ptr)
		return (ERROR);
	prev = NULL;
	lst = *(singleton());
	while (lst)
	{
		if (lst->ptr == *(void **) ptr)
		{
			if (!prev)
				*(singleton()) = lst->next;
			else
				prev->next = lst->next;
			free(lst->ptr);
			*(void **)ptr = NULL;
			return (free(lst), SUCCESS);
		}
		prev = lst;
		lst = lst->next;
	}
	return (ERROR);
}

int	ft_full_free(void)
{
	t_alloc_lst	*lst;

	while (*(singleton()))
	{
		lst = *(singleton());
		*(singleton()) = lst->next;
		if (lst->ptr)
			free(lst->ptr);
		free(lst);
	}
	return (SUCCESS);
}
