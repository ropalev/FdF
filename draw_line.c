#include "fdf.h"

int		plot_line_low(t_line *line,
		void *param)
{
	s_data	*data;

	data = (s_data *)param;
	init_line_x(line);
	while(line->x <= line->end_x)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, line->x, line->y,
				data->color++);
		if(line->D >= 0)
		{
			line->y = line->y + line->yi;
			line->D = line->D - 2 * line->dx;
		}
		line->D = line->D + 2 * line->dy;
		line->x = line->x + 1;
	}
	return (0);
}

int		plot_line_high(t_line *line, void *param)
{
	s_data	*data;

	data = (s_data *)param;
	init_line_y(line);
	while(line->y <= line->end_y)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, line->x,
				line->y, data->color++);
		if (line->D >= 0)
		{
			line->x = line->x + line->xi;
			line->D = line->D - 2 * line->dy;
		}
		line->D = line->D + 2 * line->dx;
		line->y = line->y + 1;
	}
	return (0);
}

int		plot_line(t_line *line, void *param)
{
	if (abs(line->end_y - line->start_y) < abs(line->end_x - line->start_x))
	{
		if (line->start_x > line->end_x)
		{
			start_end_change(line);
			plot_line_low(line, param);
		}
		else
			plot_line_low(line, param);
	}
	else
	{
		if (line->start_y > line->end_y)
		{
			start_end_change(line);
			plot_line_high(line, param);
		}
		else
			plot_line_high(line, param);
	}
	return (0);
}
