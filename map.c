#include "fdf.h"

void    map_draw(void *param)
{
    int x;
    int y;
    s_data *data;
    t_line	line;

    data = (s_data *)param;
    x = -1;
    while (++x < data->height)
    {
        y = -1;
        while (++y < data->width)
        {
            if (x + 1 < data->height)
            {
            	start_end_x(&line, x, y,param);
            	plot_line(&line, param);
            }
            if (y + 1 < data->width)
            {
				start_end_y(&line, x, y, param);
                plot_line(&line, param);
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

    data = (s_data *)param;
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