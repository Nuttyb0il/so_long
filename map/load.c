#include "map.h"

int ft_get_size(char *path)
{
    int fd;
    int size;
    char buffer[1024];
    int read_bytes;

    size = 0;
    fd = open(path, O_RDONLY);
    if (fd == -1)
        return (0);
    
    while (1)
    {
        read_bytes = read(fd, buffer, 1024);
        if (read_bytes <= 0)
            break;
        size += read_bytes;
    }
    close(fd);
    return (size);
}

void ft_buffer_map(char *path, t_map *map)
{
    int fd;

    map->map_string = NULL;
    fd = open(path, O_RDONLY);
    if (fd == -1)
    {
        map->map_string = (char *) malloc(0);
        return ;
    }
    map->size = ft_get_size(path);
    map->map_string = (char *) malloc(sizeof(char) * map->size);
    if (read(fd, map->map_string, map->size) == -1)
    {
        map->valid = 0;
        return ;
    }
    map->valid = 1;
    map->width = 0;
    map->height = 0;
    close(fd);
    if (map->size <= 16)
    {
        map->valid = 0;
        return ;
    }
    ft_get_attributes(map);
}

void ft_get_attributes(t_map *map)
{
    int i;
    int line_width;

    i = 0;
    line_width = 0;
    while (i < map->size)
    {
        if (map->map_string[i] == '\n') {
            map->height++;
            if (line_width != map->width && map->width != 0)
            {
                map->valid = 0;
                return ;
            }
            else
                map->width = line_width;
            line_width = 0;
        }
        else
            line_width++;
        i++;
    }
    map->height++;
}