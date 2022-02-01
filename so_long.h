#ifndef SO_LONG_H
#define SO_LONG_H

# define TILE_SIZE 64

// libc utils
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

// minilibx
# include "mlx.h"

// maps
# include "map/map.h"

// portrait utils
# include "sprites/decoder/sprite.h"

// misc utils
# include "utils/misc.h"
# include "utils/game.h"
void ft_strcat(char *src, char *dest);
void ft_strcat(char *src, char *dest);
char	*ft_strdup(char *src);
int ft_strcmp(char *s1, char *s2);
int    ft_strncmp(const char *s1, const char *s2, size_t n);
// processing/hue.c
void ft_random_hair(t_sprite *sprite);

// processing/render.c
int color_to_hex(int index, t_palette palette);
void ft_render_sprite(t_game *game, char *name, int offset_x, int offset_y);
t_sprite *ft_sprite_name(char *name, t_game *game);
void ft_render_map(t_game *game);
char *ft_render_tile(char c);

// processing/clean.c
void ft_free_game(t_game *game);
void ft_free_sprites(t_game *game);

#endif