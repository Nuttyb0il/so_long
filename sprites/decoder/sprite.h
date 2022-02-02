/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:04:19 by jallerha          #+#    #+#             */
/*   Updated: 2022/02/02 17:08:53 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H
# include "color.h"

typedef struct s_sprite
{
	t_palette	palette;
	int			*pixels;
	int			width;
	int			height;
	int			compressed;
	char		*name;
}			t_sprite;

void	ft_decode_sprite(char *name, char *path, t_sprite *sprite);
void	ft_decode_uncompressed_sprite(int fd, int **pixels, int size);
void	ft_decode_compressed_sprite(int fd, int **pixels, int size);
void	ft_new_sprite(char *name, t_sprite *sprite);
void	ft_init_matrix(int height, int width, t_sprite *sprite);
#endif