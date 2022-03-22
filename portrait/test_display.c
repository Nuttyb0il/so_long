/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:21:00 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/22 13:11:27 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx.h"
#include "../libft/includes/memory.h"

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*image;
}	t_mlx;


int redcross(t_mlx *mlx)
{
	mlx_loop_end(mlx->mlx_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->image);
	return (0);
}

int main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*image;
	int		width = 64;
	t_mlx 	mlx;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 64, 64, "test");
	mlx.mlx_ptr = mlx_ptr;
	mlx.win_ptr = win_ptr;
	image = mlx_xpm_file_to_image(mlx_ptr, "game_sprites/madeline.xpm", &width, &width);
	mlx.image = image;
	mlx_put_image_to_window(mlx_ptr, win_ptr, image, 0, 0);
	mlx_hook(mlx.win_ptr, 17, 0, redcross, &mlx);
	mlx_loop(mlx_ptr);
	mlx_destroy_image(mlx_ptr, image);
	return (0);
}