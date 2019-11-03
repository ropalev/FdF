/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvania <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 22:56:51 by lvania            #+#    #+#             */
/*   Updated: 2019/11/02 17:52:38 by lvania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_draw(void *param)
{
	t_line	line3;
	t_data	*data;
	t_line	line1;
	t_line	line2;

	data = (t_data *)param;
	line3.x = -1;
	while (++(line3.x) < data->height)
	{
		line3.y = -1;
		while (++(line3.y) < data->width)
		{
			line_init(&line1, line3.x, line3.y, param);
			if ((line3.x) + 1 < data->height)
			{
				line_init(&line2, line3.x + 1, line3.y, param);
				plot_line(&line1, &line2, param);
			}
			if ((line3.y) + 1 < data->width)
			{
				line_init(&line2, line3.x, line3.y + 1, param);
				plot_line(&line1, &line2, param);
			}
		}
	}
}

void	map_iso(void *param)
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
			x_rotation(points[x][y], -0.923599);
			y_rotation(points[x][y], -0.46373398);
			z_rotation(points[x][y], 0.46);
			y++;
		}
		x++;
	}
	map_draw(param);
}
