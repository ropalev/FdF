#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include "minilibx_macos/mlx.h"
# include <stdio.h>
# include <math.h>
# include "libft/libft.h"
# include <fcntl.h>

# define WINWIDTH	1300
# define WINHEIGHT	2500

typedef struct		s_her
{
	int				dx;
	int				dy;
	int				d;
	int				yi;
	int				xi;
	int				x;
	int				y;
}					t_her;

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
	int				color;
}					t_point;

typedef struct		s_data
{
	void			*win_ptr;
	void			*mlx_ptr;
	t_point			***matrix;
	int				width;
	int				height;
	double			par_scale;
	int				color;
}					t_data;

typedef struct		s_line
{
	double			x;
	double			y;
}					t_line;

int					plot_line_low(t_line *line1, t_line *line2, void *param);
int					plot_line_high(t_line *line1, t_line *line2, void *param);
int					plot_line(t_line *line1, t_line *line2, void *param);
t_point				*create_point(int x, int y, int z);
void				list_push_back(t_point **begin_list, int x, int y, int z);
t_point				*next_x_point(t_point *point);
int					figure_rotation(char axis, double angle, void *param);
int					figure_zoom(double scale, void *param);
int					x_rotation(t_point *point, double angle);
int					y_rotation(t_point *point, double angle);
int					z_rotation(t_point *point, double angle);
void				map_draw(void *param);
void				map_iso(void *param);
int					figure_height(double scale, void *param);
t_point				***matrix(int width, int height);
int					check_map(char *file_name, t_data *data);
void				parser(char *file, t_data *data);
void				start_end_y(t_line *line, int x, int y, void *param);
void				line_init(t_line *line, int x, int y, void *param);
void				init_low_line(t_her *perem, t_line *line1, t_line *line2);
void				init_high_line(t_her *perem, t_line *line1, t_line *line2);
#endif
