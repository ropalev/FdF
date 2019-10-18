/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvania <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:58:21 by lvania            #+#    #+#             */
/*   Updated: 2019/10/10 14:20:17 by lvania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include <stdlib.h>
#include "minilibx_macos/mlx.h"
#include <stdio.h>
#include <math.h>

typedef struct t_mouse
{
    int x;
    int y;
}               s_mouse;

typedef struct t_data
{
    void    *win_ptr;
    void    *mlx_ptr;
}              s_data;


int     plot_line_low(int start_x, int start_y, int end_x, int end_y, void *param);
int     plot_line_high(int start_x, int start_y, int end_x, int end_y, void *param);
int     plotLine(int start_x, int start_y, int end_x, int end_y, void *param);

#endif
