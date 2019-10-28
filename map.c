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

    data = (s_data *)param;;
    points = data->matrix;
    //printf("%f ", points[0][0]->x);
    y = 0;
    x = 0;
    while (x < 10)
    {
        y = 0;
        while (y < 10)
        {
            //printf("%d %d     %f\t %f\n",x,y, points[x][y]->x * 30 + WINHEIGHT/2, points[x][y]->y * 30 + WINWIDTH/2);
            if (x + 1 < 10) {
                plotLine(points[x][y]->x * 30 + WINHEIGHT/2, points[x][y]->y * 30 + WINWIDTH/2, points[x + 1][y]->x * 30 + WINHEIGHT/2, points[x + 1][y]->y * 30 + WINWIDTH/2, param);
            }
            if (y + 1 < 10) {
                plotLine(points[x][y]->x * 30 + WINHEIGHT/2, points[x][y]->y * 30 + WINWIDTH/2, points[x][y + 1]->x * 30 + WINHEIGHT/2, points[x][y + 1]->y * 30 + WINWIDTH/2, param);
            }
            y++;
        }
        x++;
    }
}

void map_iso(void *param)
{
    int x;
    int y;
    s_data *data;
    s_point ***points;
    s_point ***prev_points;

    data = (s_data *)param;;
    points = data->matrix;
    prev_points = data->matrix;

    x= 0;
    y = 0;
    while (x < 10)
    {
        y = 0;
        while (y < 10)
        {
            points[x][y]->x = (prev_points[x][y]->x + prev_points[x][y]->y) * cos(0.523599);
            points[x][y]->y = -prev_points[x][y]->z + (prev_points[x][y]->x - prev_points[x][y]->y) * sin(0.523599);
            /*x_rotation(points[x][y], 0.523599);
            y_rotation(points[x][y], 0.46373398);*/
            y++;
        }
        x++;
    }
    map_draw(param);
}