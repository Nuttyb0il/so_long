/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:39:53 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/31 14:36:59 by jallerha         ###   ########.fr       */
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
# define SPRITE_COUNT 33
# define ANIMATION_DELAY 6000

// Object animation
# define BERRY_ANIMATION_ID 255
# define SEED_ANIMATION_ID 254

typedef struct s_animation
{
	int			clock;
	int			frame;
	int			x;
	int			y;
	int			base_offset;
	int			frame_count;
	int			baf_mode;
	int			baf_direction;
	int			obj_type;
	int			stop;
}	t_animation;

typedef struct s_map
{
	char		*map;
	char		*flat;
	char		*path;
	t_chain_lst	*lines;
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

typedef struct s_game
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
	int				direction;
	int				animated_objects;
	int				anim_inits;
	int				size;
	long long int	moves;
	long long int	game_clock;
	t_animation		*animations;
}	t_game;

typedef struct s_table
{
	char			*xpm_path;
	unsigned int	crc32;
}	t_table;

char			ft_get_tile_at(t_game *game, int x, int y);
int				ft_exists(char *path);
int				ft_is_ber(char *path);
int				ft_is_valid_char(char c);
int				ft_key_hook(int keycode, t_game *game);
int				ft_legal_move(int direction, t_game *game);
int				ft_map_closed(t_chain_lst *lines);
int				ft_pseudo_random(int min, int max);
int				ft_redcross(t_game *game);
int				ft_valid_charset(char *s);
int				ft_valid_line_length(t_chain_lst *lines, int expected);
t_chain_lst		*ft_read_table(t_game *game, char *path, unsigned int crc32);
t_map			ft_load_map(char *path);
t_sprite		ft_load_sprite(t_game *game, char *path, unsigned int crc32);
t_table			ft_parse_line(t_game *game, t_chain_lst *line);
unsigned int	ft_crc32b(char *message);
void			ft_clean_exit_mlx(int code, t_game *game);
void			ft_clean_exit(int code);
void			ft_change_berries(t_game *game);
void			ft_increment_clocks(t_game *game);
void			ft_init_animations(t_game *game);
void			ft_integrity_table_fail(t_game *game, char *path);
void			ft_load_fail(t_game *game, char *path);
void			ft_load_madeline(t_game *game);
void			ft_load_objects(t_game *game);
void			ft_load_sprite_table_file(t_game *game, char *path,
					unsigned int crc32);
void			ft_load_sprite_table(t_game *game, t_table table, int i);
void			ft_load_tiles(t_game *game);
int				ft_loop_hook(t_game *game);
void			ft_print_markdown(int code, t_map *map);
void			ft_random_spawn(t_map *map);
void			ft_register_berry_anim(t_game *game, int x, int y);
void			ft_register_seed_anim(t_game *game, int x, int y);
void			ft_render_animation(t_game *game, t_animation *animation);
void			ft_render_animations(t_game *game);
void			ft_render_map(t_game *game);
void			ft_render_sprite_by_id(t_game *game, int id, int x, int y);
void			ft_stop_animation(t_game *game, int x, int y);
void			ft_set_animation(t_game *game);
void			ft_set_animation(t_game *game);
int				ft_table_size(t_game *game);
void			ft_confirm(t_game *game);
void			ft_create_window(t_game *game);
#endif