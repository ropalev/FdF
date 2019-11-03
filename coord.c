/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvania <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 17:40:52 by lvania            #+#    #+#             */
/*   Updated: 2019/11/02 17:41:52 by lvania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
