//
// Created by Leto Vania on 22/10/2019.
//

#include "fdf.h"

int     x_rotation(s_point *point, double angle)
{
    double y;
    double z;

    y = (double)point->y;
    z = (double)point->z;
    point->y = y * cos(angle) + z * sin(angle);
    point->z = -y * sin(angle) + z * cos(angle);
}

int     y_rotation(s_point *point, double angle)
{
    double x;
    double z;

    x = (double)point->x;
    z = (double)point->z;
    point->x = x * cos(angle) + z * sin(angle);
    point->z = -x * sin(angle) + z * cos(angle);
}

int     z_rotation(s_point *point, double angle)
{
    double y;
    double x;

    y = (double)point->y;
    x = (double)point->x;
    point->x = x * cos(angle) - y * sin(angle);
    point->y = x * sin(angle) + y * cos(angle);
}

int     figure_rotation(char axis,s_point *point, double angle)
{
    if (axis == 'x') {
        while (point) {
            x_rotation(point, angle);
            point = point->next;
        }
    }
    else if (axis == 'y')
    {
        while (point)
        {
            y_rotation(point, angle);
            point = point->next;
        }
    }
    else if (axis == 'z')
    {
        while (point)
        {
            z_rotation(point, angle);
            point = point->next;
        }
    }
    return(0);
}
