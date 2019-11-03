/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvania <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 17:42:23 by lvania            #+#    #+#             */
/*   Updated: 2019/11/02 18:40:11 by drinko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fdf.h"

int		keyboard_action(int keycode, void *param)
{
	if (keycode == 0)
		figure_rotation('y', -0.1, param);
	if (keycode == 1)
		figure_rotation('x', -0.1, param);
	if (keycode == 2)
		figure_rotation('y', 0.1, param);
	if (keycode == 6)
		figure_zoom(0.9, param);
	if (keycode == 7)
		figure_zoom(1.1, param);
	if (keycode == 13)
		figure_rotation('x', 0.1, param);
	if (keycode == 12)
		figure_rotation('z', -0.1, param);
	if (keycode == 14)
		figure_rotation('z', 0.1, param);
	if (keycode == 53)
		exit(0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_data *data;

	if (argc != 2)
		return (0);
	data = (t_data *)malloc(sizeof(t_data));
	check_map(argv[1], data);
	data->matrix = matrix(data->width, data->height);
	parser(argv[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			WINHEIGHT, WINWIDTH, "Window");
	mlx_hook(data->win_ptr, 2, 2, &keyboard_action, (void *)(data));
	mlx_hook(data->win_ptr, 17, 17, &close, (void *)(data));
	map_iso((void *)(data));
	mlx_loop(data->mlx_ptr);
}
