#include "map.h"

int ft_closed_map(t_map *map)
{
    unsigned int line;
    unsigned int index;
    unsigned int line_index;

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
    return (1);
}

int ft_invalid_chars(t_map *map)
{
    unsigned int index;
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

int ft_rectangle(t_map *map)
{
    return (map->width != map->height);
}

int ft_minimal_requirement(t_map *map)
{
    int spawn_points;
    int exit_points;
    int collectibles;
    unsigned int index;

    spawn_points = 0;
    exit_points = 0;
    collectibles = 0;
    index = 0;
    while (index < map->size)
    {
        if (map->map_string[index] == 'P')
            spawn_points++;
        if (map->map_string[index] == 'E')
            exit_points++;
        if (map->map_string[index] == 'C')
            collectibles++;
        index++;
    }
    return (spawn_points == 1 && exit_points == 1 && collectibles >= 1);
}