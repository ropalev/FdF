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
    return (0);
}

int     y_rotation(s_point *point, double angle)
{
    double x;
    double z;

    x = (double)point->x;
    z = (double)point->z;
    point->x = x * cos(angle) + z * sin(angle);
    point->z = -x * sin(angle) + z * cos(angle);
    return (0);
}

int     z_rotation(s_point *point, double angle)
{
    double y;
    double x;

    y = (double)point->y;
    x = (double)point->x;
    point->x = x * cos(angle) - y * sin(angle);
    point->y = x * sin(angle) + y * cos(angle);
    return (0);
}

int     figure_rotation(char axis, double angle, void *param)
{
    int x;
    int y;
    s_data *data;
    s_point ***points;

    data = (s_data *)param;
    points = data->matrix;
    if (axis == 'x') {
        while (x < 10)
        {
            y = 0;
            while (y < 10)
            {
                x_rotation(points[x][y], angle);
                y++;
            }
            x++;
        }
    }
    else if (axis == 'y')
    {
        while (x < 10) {
            y = 0;
            while (y < 10) {
                y_rotation(points[x][y], angle);
                y++;
            }
            x++;
        }
    }
    else if (axis == 'z')
    {
        while (x < 10) {
            y = 0;
            while (y < 10) {
                z_rotation(points[x][y], angle);
                y++;
            }
            x++;
        }
    }
    return(0);
}
