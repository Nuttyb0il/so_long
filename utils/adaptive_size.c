/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:17:08 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/27 17:00:08 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_compute_size(int width)
{
	if (width > 32 && width <= 48)
		return (width * 48);
	else if (width > 48 && width <= 64)
		return (width * 32);
	return (width * 64);
}

int	ft_table_size(int width)
{
	if (width > 32 && width <= 48)
		return (48);
	else if (width > 48 && width <= 64)
		return (32);
	return (64);
}
