#include "fdf.h"

int   mouse_action(int button, int x, int y, void *param)
{
    if (button == 1)
        plotLine(WINHEIGHT/2,WINWIDTH/2, x, y, param);
    if (button == 2)
        exit(0);
    return (0);
}

int     keyboard_action(int keycode, void *param)
{
    if (keycode == 0)
        exit(0);
    if (keycode == 1)
        exit(0);
    if (keycode == 2)
        exit(0);
    if (keycode == 13)
        exit(0);
    return (0);
}
int   plot(int x, int y, void *param)
{
    if ((0 < y && y < WINWIDTH) && (0 < x && x < WINHEIGHT))
        plotLine(WINHEIGHT/2,WINWIDTH/2, x, y, param);
    return (0);
}

int     main()
{
    s_data  data;
	s_mouse mouse;
	s_point *point, *point_c;

    data.mlx_ptr= mlx_init();
    data.win_ptr = mlx_new_window(data.mlx_ptr, WINHEIGHT, WINWIDTH, "Maybe?!?!?!");
    mlx_pixel_put(data.mlx_ptr, data.win_ptr, WINHEIGHT/2,WINWIDTH/2, 0xFFFFFF);
	//mlx_string_put(data.mlx_ptr, data.win_ptr, 300, 300, 0xFFFFFF, "I'm FUCKING GENIOUS");
	mlx_hook(data.win_ptr, 4, 4, &mouse_action, (void *)(&data));
    //draw_matrix(data);
    mlx_hook(data.win_ptr, 6, 6, &plot, (void *)(&data));
    mlx_hook(data.win_ptr, 2, 2, &keyboard_action, (void *)(&data));
    mlx_loop(data.mlx_ptr);
}
