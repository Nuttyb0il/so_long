#ifndef PALETTE_H
# define PALETTE_H

typedef struct	s_color
{
    unsigned char	r;
    unsigned char	g;
    unsigned char	b;
}				t_color;

typedef struct	s_palette
{
    t_color		*colors;
    int				size;
}				t_palette;

void ft_get_palette(int fd, t_palette *palette);
t_palette ft_new_palette();
#endif