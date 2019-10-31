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
#include <fcntl.h>

#define WINWIDTH 1000
#define WINHEIGHT 2000

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
    double          color_coef;
    int             color;
}                   s_point;

typedef  struct		s_line
{
	int dx;
	int dy;
	int D;
	int yi;
	int xi;
	int x;
	int y;
	int start_x;
	int start_y;
	int end_x;
	int end_y;
}					t_line;

typedef struct      t_data
{
    void            *win_ptr;
    void            *mlx_ptr;
    s_point         ***matrix;
    int             width;
    int             height;
    int             iso_scale;
    int             par_scale;
    int             z_max;
    int             z_min;
    int             color;
}                   s_data;


int     plot_line_low(t_line *line, void *param);
int     plot_line_high(t_line *line, void *param);
int     plot_line(t_line *line, void *param);
s_point *create_point(int x, int y, int z);
void	list_push_back(s_point **begin_list, int x, int y, int z);
s_point *next_x_point(s_point *point);
int     figure_rotation(char axis, double angle, void *param);
int     figure_zoom(double scale, void *param);
int     x_rotation(s_point *point, double angle);
int     y_rotation(s_point *point, double angle);
int     z_rotation(s_point *point, double angle);
void    map_draw(void *param);
void    map_iso(void *param);
int     figure_height(double scale, void *param);

s_point ***matrix(int width, int height);
int     check_map(char *file_name, s_data *data);
void    parser(char *file,s_data *data);
int     check_maxyz(s_data *data);
int     change_color(s_data *data);
void init_line_y(t_line *line);
void init_line_x(t_line *line);
void start_end_x(t_line *line, int x, int y, void *param);
void start_end_y(t_line *line, int x, int y, void *param);
void start_end_change(t_line *line);



#endif
