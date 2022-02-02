/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:22:51 by jallerha          #+#    #+#             */
/*   Updated: 2022/02/02 17:23:22 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_H
# define GEOMETRY_H

typedef struct s_point {
	int	x;
	int	y;
}	t_point;

typedef struct s_rectangle {
	t_point	p1;
	t_point	p2;
}	t_rectangle;

#endif