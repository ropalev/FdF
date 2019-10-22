//
// Created by Leto Vania on 20/10/2019.
//

#include "fdf.h"

s_point *create_point(int x, int y, int z)
{
    s_point *point;

    point->x = x;
    point->x_p = x;
    point->y = y;
    point->y_p = y;
    point->z = z;
    point->z_p = z;
    point->next = NULL;
    return (point);
}