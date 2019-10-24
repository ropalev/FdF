//
// Created by Leto Vania on 23/10/2019.
//

#include "fdf.h"


int     point_scale(s_point *point, double scale)
{
    point->x *= scale;
    point->y *= scale;
    point->z *= scale;
    point++;
    return (0);
}

int     figure_zoom(s_point *point, double scale)
{
    while (point)
        point_scale(point,scale);
    return (0);
}
