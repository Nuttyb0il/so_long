/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 19:34:27 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/01 15:27:44 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_index(char *haystack, char *needle)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (haystack[i])
	{
		j = 0;
		k = i;
		while (needle[j])
		{
			if (haystack[k] != needle[j])
				break ;
			j++;
			k++;
		}
		if (!needle[j])
			return (i);
		i++;
	}
	return (-1);
}
