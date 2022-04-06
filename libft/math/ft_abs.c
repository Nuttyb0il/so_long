/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:12:51 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/01 14:21:50 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

long	ft_abs_l(long n)
{
	if (n < 0)
		return (-n);
	return (n);
}

long long	ft_abs_ll(long long n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	ft_abs_c(char n)
{
	if (n < 0)
		return (-n);
	return (n);
}
