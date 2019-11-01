#include "fdf.h"

int     plot_line_low(t_line *line1, t_line *line2, void *param)
{
	t_her	perem;
    s_data  *data;

    data = (s_data *)param;
    init_low_line(&perem,line1,line2);
    while(perem.x <= line2->x)
    {
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, perem.x, perem.y,
        		data->color++);
        if(perem.D >= 0)
        {
            perem.y = perem.y + perem.yi;
            perem.D = perem.D - 2 * perem.dx;
        }
        perem.D = perem.D + 2 * perem.dy;
        perem.x = perem.x + 1;
    }
    return (0);
}

int     plot_line_high(t_line *line1, t_line *line2, void *param)
{
	t_her	perem;
    s_data  *data;

    data = (s_data *)param;
    init_high_line(&perem,line1, line2);
    while(perem.y <= line2->y)
    {
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, perem.x, perem.y,
        		data->color++);
        if(perem.D >= 0)
        {
            perem.x = perem.x + perem.xi;
            perem.D = perem.D - 2 * perem.dy;
        }
        perem.D = perem.D + 2 * perem.dx;
        perem.y = perem.y + 1;
    }
    return (0);
}

int     plotLine(t_line *line1, t_line *line2, void *param)
{
    if (fabs(line2->y - line1->y) < fabs(line2->x - line1->x))
    {
        if (line1->x > line2->x)
            plot_line_low(line2, line1, param);
        else
			plot_line_low(line1, line2, param);
    }
    else
    {
        if (line1->y > line2->y)
			plot_line_high(line2, line1, param);
        else
			plot_line_high(line1, line2, param);
    }
    return (0);
}
