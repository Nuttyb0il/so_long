#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>


unsigned int ft_pseudo_random(int min, int max)
{
    int fd;
    int random;

    fd = open("/dev/urandom", O_RDONLY);
    if (fd == -1)
        return (0);
    read(fd, &random, sizeof(int));
    close(fd);
    if (random < 0)
        random *= -1;
    return (random % (max - min + 1) + min);
}