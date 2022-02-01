#ifndef MAP_H
# define MAP_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
typedef struct t_map
{
    char *map_string;
    unsigned int size;
    unsigned int height;
    unsigned int width;
    int valid;
    int player_x;
    int player_y;
}   t_map;

void ft_buffer_map(char *path, t_map *map);
int ft_get_size(char *path);
void ft_get_attributes(t_map *map);

// map/integrity.c
int ft_invalid_chars(t_map *map);
int ft_closed_map(t_map *map);
int ft_rectangle(t_map *map);
int ft_minimal_requirement(t_map *map);

#endif