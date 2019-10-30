//
// Created by Leto Vania on 24/10/2019.
//

#include "fdf.h"

void    map_draw(void *param)
{
    int x;
    int y;
    s_data *data;
    s_point ***points;

    data = (s_data *)param;
    points = data->matrix;
    x = -1;
    while (++x < data->height)
    {
        y = -1;
        while (++y < data->width)
        {
            if (x + 1 < data->height) {
                plotLine(points[x][y]->x * 30 + WINHEIGHT/2, points[x][y]->y * 30 + WINWIDTH/2,
                        points[x + 1][y]->x * 30 + WINHEIGHT/2, points[x + 1][y]->y * 30 + WINWIDTH/2, param);
            }
            if (y + 1 < data->width) {
                plotLine(points[x][y]->x * 30 + WINHEIGHT/2, points[x][y]->y * 30 + WINWIDTH/2,
                        points[x][y + 1]->x * 30 + WINHEIGHT/2, points[x][y + 1]->y * 30 + WINWIDTH/2, param);
            }
        }
    }
}

void map_iso(void *param)
{
    int x;
    int y;
    s_data *data;
    s_point ***points;

    data = (s_data *)param;;
    points = data->matrix;
    x= 0;
    while (x < data->height)
    {
        y = 0;
        while (y < data->width)
        {
            x_rotation(points[x][y], -0.923599);
            y_rotation(points[x][y], -0.46373398);
            z_rotation(points[x][y],0.46);
            y++;
        }
        x++;
    }
    map_draw(param);
}