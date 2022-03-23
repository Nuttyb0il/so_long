/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:39:53 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/23 19:41:26 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/includes/lists.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# define CHARSET "01CEP\n"

// error section
# define INVALID_COLLECTIBLES 255
# define INVALID_SPAWNS 254
# define INVALID_EXITS 253
# define INVALID_MAP_CHARACTERS 252
# define INVALID_LINE_LENGTH 251
# define MAP_NOT_CLOSED 250

// Keys
# define UP 119
# define DOWN 115
# define RIGHT 100
# define LEFT 97
# define ESC 65307

// Other constants
# define SPRITE_COUNT 21

typedef struct s_map
{
	char		*map;
	char		*flat;
	char		*path;
	t_chain_lst *lines;
	int			length;
	int			height;
	int			width;
	int			sanity;
	int			fd;
	int			collectibles;
	int			spawns;
	int			exits;
}	t_map;

typedef struct s_sprite
{
	char				*path;
	unsigned int		computed_crc32;
	unsigned int		crc32;
	int					id;
	void				*image;
}	t_sprite;

typedef struct	s_game
{
	t_map			map_data;
	t_sprite		*sprites;
	void			*mlx_ptr;
	void			*game_window;
	void			*player_image;
	int				height;
	int				width;
	int				sprites_init;
	int				window_height;
	int				window_width;
	int				x;
	int				y;
	long long int	moves;
	long long int	game_clock;
}	t_game;


t_map			ft_load_map(char *path);
void			clean_exit(int code);
int				ft_valid_line_length(t_chain_lst *lines, int expected);
int				ft_map_closed(t_chain_lst *lines);
int				ft_valid_charset(char *s);
void			ft_print_markdown(int code, t_map *map);
int				ft_is_valid_char(char c);
int				ft_is_ber(char *path);
void			ft_load_sprites(t_game *game);
void			clean_exit_mlx(int code, t_game *game);
void			ft_render_sprite_by_id(t_game *game, int id, int x, int y);
void			ft_render_map(t_game *game);
unsigned int	ft_crc32b(char *message);
int				ft_legal_move(int direction, t_game *game);
char			ft_get_tile_at(t_game *game, int x, int y);
#endif