#include "fdf.h"

void init_line_y(t_line *line)
{
	line->dx = line->end_x - line->start_x;
	line->dy = line->end_y - line->start_y;
	line->yi = 1;
	if (line->dy < 0)
	{
		line->yi = -1;
		line->dy = -line->dy;
	}
	line->D = 2 * line->dy - line->dx;
	line->y = line->start_y;
	line->x = line->start_x;
}

void init_line_x(t_line *line)
{
	line->dx = line->end_x - line->start_x;
	line->dy = line->end_y - line->start_y;
	line->xi = 1;
	if (line->dx < 0)
	{
		line->xi = -1;
		line->dx = -line->dx;
	}
	line->D = 2 * line->dx - line->dy;
	line->y = line->start_y;
	line->x = line->start_x;
}

void start_end_x(t_line *line, int x, int y, void *param)
{
	s_data *data;
	s_point ***points;

	data = (s_data *)param;
	points = data->matrix;

	line->start_x = points[x][y]->x * data->par_scale + WINHEIGHT/2;
	line->start_y = points[x][y]->y * data->par_scale + WINWIDTH/2;
	line->end_x = points[x + 1][y]->x * data->par_scale + WINHEIGHT/2;
	line->end_y = points[x + 1][y]->y * data->par_scale + WINWIDTH/2;
}

void start_end_y(t_line *line, int x, int y, void *param)
{
	s_data *data;
	s_point ***points;

	data = (s_data *)param;
	points = data->matrix;

	line->start_x = points[x][y]->x * data->par_scale + WINHEIGHT/2;
	line->start_y = points[x][y]->y * data->par_scale + WINWIDTH/2;
	line->end_x = points[x][y + 1]->x * data->par_scale + WINHEIGHT/2;
	line->end_y = points[x][y + 1]->y * data->par_scale + WINWIDTH/2;
}

void start_end_change(t_line *line)
{
	int tmp;

	tmp = line->start_x;
	line->start_x = line->end_x;
	line->end_x = tmp;
	tmp = line->start_y;
	line->start_y = line->end_y;
	line->end_y = tmp;
}