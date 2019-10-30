//
// Created by Leto Vania on 23/10/2019.
//

#include "fdf.h"

int     figure_zoom(double scale, void *param)
{
    int x;
    int y;
    s_data *data;
    s_point ***points;

    data = (s_data *)param;
    points = data->matrix;

    x = 0;
    while (x < data->height)
    {
        y = 0;
        while (y < data->width)
        {
            points[x][y]->x *= scale;
            points[x][y]->y *= scale;
            y++;
        }
        x++;
    }
    mlx_clear_window(data->mlx_ptr, data->win_ptr);
    map_draw(param);
    return (0);
}

int     figure_height(double scale, void *param)
{
    int x;
    int y;
    s_data *data;
    s_point ***points;

    data = (s_data *)param;
    points = data->matrix;

    x = 0;
    while (x < data->height)
    {
        y = 0;
        while (y < data->width)
        {
            points[x][y]->z += scale;
            printf("%f", points[x][y]->z);
            y++;
        }
        x++;
    }
    mlx_clear_window(data->mlx_ptr, data->win_ptr);
    map_draw(param);
    return (0);
}