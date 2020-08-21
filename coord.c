#include "fdf.h"

t_point		*create_point(int x, int y, int z)
{
	t_point	*point;

	point = (t_point *)malloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	point->z = z;
	point->color = 0xFFFFFF;
	return (point);
}
