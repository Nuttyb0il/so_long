/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:25:09 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/01 14:21:06 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_factorial(int n)
{
	if (n < 0)
		return (0);
	if (n == 0)
		return (1);
	return (n * ft_factorial(n - 1));
}

long	ft_factorial_l(long n)
{
	if (n < 0)
		return (0);
	if (n == 0)
		return (1);
	return (n * ft_factorial_l(n - 1));
}

long long	ft_factorial_ll(long long n)
{
	if (n < 0)
		return (0);
	if (n == 0)
		return (1);
	return (n * ft_factorial_ll(n - 1));
}
