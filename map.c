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
            if (x + 1 < data->height)
            {
            	plot_line(points[x][y]->x * data->par_scale + WINHEIGHT/2,
            			points[x][y]->y * data->par_scale + WINWIDTH/2,
                        points[x + 1][y]->x * data->par_scale + WINHEIGHT/2, points[x + 1][y]->y * data->par_scale + WINWIDTH/2, param);
            }
            if (y + 1 < data->width)
            {
                plot_line(points[x][y]->x * data->par_scale + WINHEIGHT/2,
                		points[x][y]->y * data->par_scale + WINWIDTH/2,
                        points[x][y + 1]->x * data->par_scale + WINHEIGHT/2, points[x][y + 1]->y * data->par_scale + WINWIDTH/2, param);
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