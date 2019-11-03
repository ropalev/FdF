/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_zoom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvania <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 17:47:14 by lvania            #+#    #+#             */
/*   Updated: 2019/11/02 17:48:09 by lvania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		figure_zoom(double scale, void *param)
{
	int		x;
	int		y;
	t_data	*data;
	t_point	***points;

	data = (t_data *)param;
	points = data->matrix;
	x = 0;
	while (x < data->height)
	{
		y = 0;
		while (y < data->width)
		{
			points[x][y]->x *= scale;
			points[x][y]->y *= scale;
			points[x][y]->z *= scale;
			y++;
		}
		x++;
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	map_draw(param);
	return (0);
}

int		figure_height(double scale, void *param)
{
	int		x;
	int		y;
	t_data	*data;
	t_point	***points;

	data = (t_data *)param;
	points = data->matrix;
	x = 0;
	while (x < data->height)
	{
		y = 0;
		while (y < data->width)
		{
			points[x][y]->z += scale;
			y++;
		}
		x++;
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	map_draw(param);
	return (0);
}
