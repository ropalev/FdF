#include "fdf.h"

void init_line_y(t_line *line, int end_x, int start_x, int end_y, int start_y)
{
	line->dx = end_x - start_x;
	line->dy = end_y - start_y;
	line->yi = 1;
	if (line->dy < 0)
	{
		line->yi = -1;
		line->dy = -line->dy;
	}
	line->D = 2 * line->dy - line->dx;
	line->y = start_y;
	line->x = start_x;
}

void init_line_x(t_line *line, int end_x, int start_x, int end_y, int start_y)
{
	line->dx = end_x - start_x;
	line->dy = end_y - start_y;
	line->xi = 1;
	if (line->dx < 0)
	{
		line->xi = -1;
		line->dx = -line->dx;
	}
	line->D = 2 * line->dx - line->dy;
	line->y = start_y;
	line->x = start_x;
}
/*
void start_end(t_line *line)
{
	line->start_x = points[x][y]->x * data->par_scale + WINHEIGHT/2;
	line->start_y = points[x][y]->y * data->par_scale + WINWIDTH/2;
	line->end_x = points[x + 1][y]->x * data->par_scale + WINHEIGHT/2;
	line->end_y = points[x + 1][y]->y * data->par_scale + WINWIDTH/2
}*/