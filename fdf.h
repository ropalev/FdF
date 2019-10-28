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
#include "libft/libft.h"

#define WINWIDTH 1000
#define WINHEIGHT 1000
#define ROW_NUM 10
#define COL_NUM 10
#define MATRIX_SHIFT_X 5;
#define MATRIX_SHIFT_Y 5;

typedef struct t_mouse
{
    int x;
    int y;
}               s_mouse;

typedef struct      t_point
{
    double          x;
    double          y;
    double          z;
    int             x_p;
    int             y_p;
    int             z_p;
    char            *color;
}                   s_point;

typedef struct      t_data
{
    void            *win_ptr;
    void            *mlx_ptr;
    s_point         ***matrix;
}                   s_data;

typedef struct      t_map
{
    double scale;
    double x_center;
    double y_center;
    double x_shift_to_zero;
    double y_shift_to_zero;
}               s_map;

int     plot_line_low(int start_x, int start_y, int end_x, int end_y, void *param);
int     plot_line_high(int start_x, int start_y, int end_x, int end_y, void *param);
int     plotLine(int start_x, int start_y, int end_x, int end_y, void *param);
s_point *create_point(int x, int y, int z);
void	list_push_back(s_point **begin_list, int x, int y, int z);
s_point     *parser(char *file);
s_point *next_x_point(s_point *point);
s_point ***matrix(void);
int     figure_rotation(char axis, double angle, void *param);
int     figure_zoom(double scale, void *param);
int     x_rotation(s_point *point, double angle);
int     y_rotation(s_point *point, double angle);
int     z_rotation(s_point *point, double angle);
void    map_draw(void *param);
void map_iso(void *param);



#endif
