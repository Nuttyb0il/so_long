/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:14:38 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/01 14:20:33 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_pow(int n, int pow)
{
	int			i;
	int			result;

	i = 0;
	result = 1;
	while (i < pow)
	{
		result *= n;
		i++;
	}
	return (result);
}

long	ft_pow_l(long n, int pow)
{
	int			i;
	long		result;

	i = 0;
	result = 1;
	while (i < pow)
	{
		result *= n;
		i++;
	}
	return (result);
}

long long	ft_pow_ll(long long n, int pow)
{
	int			i;
	long long	result;

	i = 0;
	result = 1;
	while (i < pow)
	{
		result *= n;
		i++;
	}
	return (result);
}
