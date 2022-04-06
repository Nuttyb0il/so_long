/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:23:51 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/01 14:27:43 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/put.h"
#include "../includes/constants.h"
#include "../includes/memory.h"

void	assert(int condition)
{
	if (!condition)
	{
		ft_full_free();
		exit(1);
	}
}

void	assert_msg(int condition, char *msg)
{
	if (!condition)
	{
		ft_putendl_fd(msg, STDERR);
		ft_full_free();
		exit(1);
	}
}

void	assert_verbose(int condition, char *fail, char *success)
{
	if (!condition)
	{
		ft_putendl_fd(fail, STDERR);
		ft_full_free();
		exit(1);
	}
	else
		ft_putendl_fd(success, STDERR);
}
