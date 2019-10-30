//
// Created by Leto Vania on 20/10/2019.
//

#include "fdf.h"

s_point *create_point(int x, int y, int z)
{
    s_point *point;

    point = (s_point *)malloc(sizeof(s_point));
    point->x = x;
    point->y = y;
    point->z = z;
    point->x_p = x;
    point->y_p = y;
    point->z_p = z;
    point->color = 0xFFFFFF;
    return (point);
}