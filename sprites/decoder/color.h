/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:04:09 by jallerha          #+#    #+#             */
/*   Updated: 2022/02/02 17:19:20 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}				t_color;

typedef struct s_palette
{
	t_color			*colors;
	int				size;
}				t_palette;

void		ft_get_palette(int fd, t_palette *palette);
t_palette	ft_new_palette(void);
#endif