/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvania <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 22:56:51 by lvania            #+#    #+#             */
/*   Updated: 2019/11/01 23:01:26 by lvania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_draw(void *param)
{
	int		x;
	int		y;
	s_data	*data;
	t_line	line1;
	t_line	line2;

	data = (s_data *)param;
	x = -1;
	while (++x < data->height)
	{
		y = -1;
		while (++y < data->width)
		{
			line_init(&line1, x, y, param);
			if (x + 1 < data->height)
			{
				line_init(&line2, x + 1, y, param);
				plotLine(&line1, &line2, param);
			}
			if (y + 1 < data->width)
			{
				line_init(&line2, x, y + 1, param);
				plotLine(&line1, &line2, param);
			}
		}
	}
}

void map_iso(void *param)
{
	int		x;
	int		y;
	s_data	*data;
	s_point	***points;

	data = (s_data *)param;;
	points = data->matrix;
	x= 0;
	while (x < data->height)
	{
		y = 0;
		while (y < data->width)
		{
			x_rotation(points[x][y], -0.923599);
			y_rotation(points[x][y], -0.46373398);
			z_rotation(points[x][y],0.46);
			y++;
		}
		x++;
	}
	map_draw(param);
}
