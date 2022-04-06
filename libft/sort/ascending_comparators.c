/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascending_comparators.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:23:03 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/01 14:28:46 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	int_asc_comparator(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int	double_asc_comparator(const void *a, const void *b)
{
	return (*(double *)a - *(double *)b);
}

int	char_asc_comparator(const void *a, const void *b)
{
	return (*(char *)a - *(char *)b);
}

int	float_asc_comparator(const void *a, const void *b)
{
	return (*(float *)a - *(float *)b);
}
