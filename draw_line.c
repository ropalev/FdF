#include "fdf.h"

int     plot_line_low(int start_x, int start_y, int end_x, int end_y, void *param)
{
    int dx, dy, D, yi, x, y;
    s_data  *data;

    data = (s_data *)param;
    dx = end_x - start_x;
    dy = end_y - start_y;
    yi = 1;
    if (dy < 0)
    {
        yi = -1;
        dy = -dy;
    }
    D = 2 * dy - dx;
    y = start_y;
    x = start_x;
    while(x <= end_x)
    {
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xFFFFFF);
        if(D >= 0)
        {
            y = y + yi;
            D = D - 2 * dx;
        }
        D = D + 2 * dy;
        x = x + 1;
    }
    return (0);
}

int     plot_line_high(int start_x, int start_y, int end_x, int end_y, void *param)
{
    int dx, dy, D, yi, x, y,xi;
    s_data  *data;

    data = (s_data *)param;
    dx = end_x - start_x;
    dy = end_y - start_y;
    xi = 1;
    if (dx < 0)
    {
        xi = -1;
        dx = -dx;
    }
    D = 2 * dx - dy;
    y = start_y;
    x = start_x;
    while(y <= end_y)
    {
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xFFFFFF);
        if(D >= 0)
        {
            x = x + xi;
            D = D - 2 * dy;
        }
        D = D + 2 * dx;
        y = y + 1;
    }
    return (0);
}

int     plotLine(int start_x, int start_y, int end_x, int end_y, void *param)
{
    if (abs(end_y - start_y) < abs(end_x - start_x))
    {
        if (start_x > end_x)
            plot_line_low(end_x, end_y, start_x, start_y, param);
        else
            plot_line_low(start_x, start_y, end_x, end_y, param);
    }
    else
    {
        if (start_y > end_y)
            plot_line_high(end_x, end_y, start_x, start_y, param);
        else
            plot_line_high(start_x, start_y, end_x, end_y, param);
    }
    return (0);
}
