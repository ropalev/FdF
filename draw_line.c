#include "fdf.h"

int		plot_line_low(int start_x, int start_y, int end_x, int end_y, void *param)
{
	t_line	line;
	s_data	*data;

	data = (s_data *)param;
	init_line_y(&line, end_x, start_x, end_y, start_y);
	while(line.x <= end_x)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, line.x, line.y, data->color++);
		if(line.D >= 0)
		{
			line.y = line.y + line.yi;
			line.D = line.D - 2 * line.dx;
		}
		line.D = line.D + 2 * line.dy;
		line.x = line.x + 1;
	}
	return (0);
}

int		plot_line_high(int start_x, int start_y, int end_x,
		int end_y, void *param)
{
	t_line	line;
	s_data	*data;

	data = (s_data *)param;
	init_line_x(&line, end_x, start_x, end_y, start_y);
	while(line.y <= end_y)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, line.x,
				line.y, data->color++);
		if (line.D >= 0)
		{
			line.x = line.x + line.xi;
			line.D = line.D - 2 * line.dy;
		}
		line.D = line.D + 2 * line.dx;
		line.y = line.y + 1;
	}
	return (0);
}

int		plot_line(int start_x, int start_y, int end_x, int end_y, void *param)
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
