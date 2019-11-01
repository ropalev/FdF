/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvania <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 22:52:34 by lvania            #+#    #+#             */
/*   Updated: 2019/11/01 22:56:08 by lvania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		x_rotation(s_point *point, double angle)
{
	double	y;
	double	z;

	y = (double)point->y;
	z = (double)point->z;
	point->y = y * cos(angle) + z * sin(angle);
	point->z = -y * sin(angle) + z * cos(angle);
	return (0);
}

int		y_rotation(s_point *point, double angle)
{
	double	x;
	double	z;

	x = (double)point->x;
	z = (double)point->z;
	point->x = x * cos(angle) + z * sin(angle);
	point->z = -x * sin(angle) + z * cos(angle);
	return (0);
}

int		z_rotation(s_point *point, double angle)
{
	double	y;
	double	x;

	y = (double)point->y;
	x = (double)point->x;
	point->x = x * cos(angle) - y * sin(angle);
	point->y = x * sin(angle) + y * cos(angle);
	return (0);
}

int		figure_rotation(char axis, double angle, void *param)
{
	int		x;
	int		y;
	s_data	*data;
	s_point	***points;

	data = (s_data *)param;
	points = data->matrix;
	x = -1;
	while (++x < data->height)
	{
		y = -1;
		while (++y < data->width)
		{
			if (axis == 'x')
				x_rotation(points[x][y], angle);
			else if (axis == 'y')
				y_rotation(points[x][y], angle);
			else if (axis == 'z')
				z_rotation(points[x][y], angle);
		}
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	map_draw(param);
	return (0);
}
