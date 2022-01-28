#include "map.h"

int ft_closed_map(t_map *map)
{
    int line;
    int index;
    int line_index;

    line = 0;
    index = 0;
    line_index = 0;
    while (index < map->size)
    {
        if (map->map_string[index] == '\n')
        {
            line++;
            index++;
            line_index = 0;
        }
        if ((line == 0 || line == map->height - 1) && map->map_string[index] != '1')
            return (0);
        else if (line != 0 && line != map->height - 1
                && (line_index == 0 || line_index == map->width - 1)
                && map->map_string[index] != '1')
            return (0);
        line_index++;
        index++;
    }
}

int ft_invalid_chars(t_map *map)
{
    int index;
    char c;

    index = 0;
    while (index < map->size)
    {   
        c = map->map_string[index];
        if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P' && c != '\n')
            return (0);
        index++;
    }
    return (1);
}