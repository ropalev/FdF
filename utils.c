#include "fdf.h"

void line_init(t_line *line, int x, int y, void *param)
{
	s_data *data;
	s_point ***points;

	data = (s_data *)param;
	points = data->matrix;

	line->x = points[x][y]->x * data->par_scale + WINHEIGHT/2;
	line->y = points[x][y]->y * data->par_scale + WINWIDTH/2;
}

void init_low_line(t_her *perem, t_line *line1, t_line *line2)
{
	perem->dx = line2->x - line1->x;
	perem->dy = line2->y - line1->y;
	perem->yi = 1;
	if (perem->dy < 0)
	{
		perem->yi = -1;
		perem->dy = -perem->dy;
	}
	perem->D = 2 * perem->dy - perem->dx;
	perem->y = line1->y;
	perem->x = line1->x;
}

void init_high_line(t_her *perem, t_line *line1, t_line *line2)
{
	perem->dx = line2->x - line1->x;
	perem->dy = line2->y - line1->y;
	perem->xi = 1;
	if (perem->dx < 0)
	{
		perem->xi = -1;
		perem->dx = -perem->dx;
	}
	perem->D = 2 * perem->dx - perem->dy;
	perem->y = line1->y;
	perem->x = line1->x;
}

/*

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

*/