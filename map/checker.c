#include "map.h"
#include <stdio.h>
int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);
    t_map map;

    ft_buffer_map(argv[1], &map);

    // Perform checks
    if (!ft_closed_map(&map))
    {
        printf("Map is not closed\n");
        return (1);
    }
    if (!ft_invalid_chars(&map))
    {
        printf("Map contains invalid characters\n");
        return (1);
    }
    if (!ft_rectangle(&map))
    {
        printf("Map is not rectangular\n");
        return (1);
    }
    if (!ft_minimal_requirement(&map))
    {
        printf("Map does not meet minimal requirements\n");
        return (1);
    }
    return (0);
}