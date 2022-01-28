#include "map.h"
#include <stdio.h>
int main(void)
{
    t_map map;

    ft_buffer_map("test.ber", &map);
    puts("Map buffered !");
    puts("------------");
    printf("Size : %d\n", map.size);
    printf("Height : %d\n", map.height);
    printf("Width : %d\n", map.width);
    printf("Valid : %d\n", map.valid);
    for (int i = 0; i < map.size; i++)
        printf("%c", map.map_string[i]);
    puts("\n------------\nPerforming sanity checks\n------------");
    printf("Closed map -> ");
    if (ft_closed_map(&map))
        puts("OK");
    else
        puts("KO");
    printf("Invalid chars -> ");
    if (ft_invalid_chars(&map))
        puts("OK");
    else
        puts("KO");

    // TODO : Check for 1 exit, 1 spawn, atleast 1 collectible
    // TODO : Check if map is rectangular
    return (0);
}