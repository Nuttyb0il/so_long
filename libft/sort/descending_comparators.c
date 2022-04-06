/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   descending_comparators.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 15:12:41 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/01 14:28:27 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	int_desc_comparator(const void *a, const void *b)
{
	return (*(int *)b - *(int *)a);
}

int	double_desc_comparator(const void *a, const void *b)
{
	return (*(double *)b - *(double *)a);
}

int	char_desc_comparator(const void *a, const void *b)
{
	return (*(char *)b - *(char *)a);
}

int	float_desc_comparator(const void *a, const void *b)
{
	return (*(float *)b - *(float *)a);
}
