#ifndef POINT_H
#define POINT_H

typedef struct s_point {
    int x;
    int y;
} t_point;

typedef struct s_rectangle {
    t_point p1;
    t_point p2;
} t_rectangle;

#endif