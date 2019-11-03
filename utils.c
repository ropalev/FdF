/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvania <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 17:48:36 by lvania            #+#    #+#             */
/*   Updated: 2019/11/02 18:06:20 by lvania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	line_init(t_line *line, int x, int y, void *param)
{
	t_data	*data;
	t_point	***points;

	data = (t_data *)param;
	points = data->matrix;
	line->x = points[x][y]->x * data->par_scale + WINHEIGHT / 2;
	line->y = points[x][y]->y * data->par_scale + WINWIDTH / 2;
}

void	init_low_line(t_her *perem, t_line *line1, t_line *line2)
{
	perem->dx = line2->x - line1->x;
	perem->dy = line2->y - line1->y;
	perem->yi = 1;
	if (perem->dy < 0)
	{
		perem->yi = -1;
		perem->dy = -perem->dy;
	}
	perem->d = 2 * perem->dy - perem->dx;
	perem->y = line1->y;
	perem->x = line1->x;
}

void	init_high_line(t_her *perem, t_line *line1, t_line *line2)
{
	perem->dx = line2->x - line1->x;
	perem->dy = line2->y - line1->y;
	perem->xi = 1;
	if (perem->dx < 0)
	{
		perem->xi = -1;
		perem->dx = -perem->dx;
	}
	perem->d = 2 * perem->dx - perem->dy;
	perem->y = line1->y;
	perem->x = line1->x;
}
