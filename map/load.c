#include "map.h"

int ft_get_size(char *path)
{
    int fd;
    int size;
    char buffer[1];

    fd = open(path, O_RDONLY);
    if (fd == -1)
        return (0);
    while (read(fd, buffer, 1) > 0)
        size++;
    return (size);
}

t_map ft_buffer_map(char *path)
{
    int fd;
    t_map output;

    output.map_string = NULL;
    fd = open(path, O_RDONLY);
    if (fd == -1)
    {
        output.map_string = (char *) malloc(0);
        return output;
    }
    output.map_file_size = ft_get_size(path);
    output.map_string = (char *) malloc(sizeof(char) * output.map_file_size);
    read(fd, &output.map_string, output.map_file_size);
    return (output);
}