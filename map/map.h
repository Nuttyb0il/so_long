#ifndef MAP_H
# define MAP_H
# define MAP_CHARSET = "01CEP"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
typedef struct t_map
{
    char *map_string;
    int map_file_size;
}   t_map;
#endif