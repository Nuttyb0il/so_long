/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:08:43 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/21 14:33:45 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/memory.h"
#include "../libft/includes/colors.h"
#include "../libft/includes/printf.h"
#include <unistd.h>

void	clean_exit(int code)
{
	ft_full_free();
	ft_printf(INDIANRED1"\nLeaks :\n");
	system("leaks -q so_long");
	ft_printf(RESET"\r");
	exit(code);
}
