#include "fdf.h"
#define WINWIDTH 1250
#define WINHEIGHT 1920
int     plot_line_low(int start_x, int start_y, int end_x, int end_y, void *param);
int     plot_line_high(int start_x, int start_y, int end_x, int end_y, void *param);
int     plotLine(int start_x, int start_y, int end_x, int end_y, void *param);

int   pr(int button, int x, int y, void *param)
{
    if (button == 1)
        plotLine(WINHEIGHT/2,WINWIDTH/2, x, y, param);
    if (button == 2)
        exit(0);
    return (0);
}

int     draw_matrix(s_data data)
{
    int len_x;
    int len_y;
    int x;
    int y;
    int dx, dy;

    x = 0;
    len_x = 5;
    len_y = 4;
    dx = WINWIDTH / len_x;
    dy = WINHEIGHT / len_y;
    while (x <= WINWIDTH)
    {
        y = 0;
        while (y <= WINHEIGHT)
        {
            mlx_pixel_put(data.mlx_ptr, data.win_ptr, x, x, 0x00FF00);
            printf("y:%d %d\nx:%d %d\n\n", y, WINHEIGHT, x, WINWIDTH);
            y += dy;
        }
        //printf("y:%d %d  x: %d\n", y, WINWIDTH, x);
        x += dx;
    }
    return (0);
}
int     main()
{
    s_data  data;
	s_mouse mouse;

    data.mlx_ptr= mlx_init();
    data.win_ptr = mlx_new_window(data.mlx_ptr, WINHEIGHT, WINWIDTH, "Maybe?!?!?!");
    mlx_pixel_put(data.mlx_ptr, data.win_ptr, WINHEIGHT/2,WINWIDTH/2, 0xFFFFFF);
	//mlx_string_put(data.mlx_ptr, data.win_ptr, 300, 300, 0xFFFFFF, "I'm FUCKING GENIOUS");
	mlx_hook(data.win_ptr, 4, 0, &pr, (void *)(&data));
    draw_matrix(data);
    mlx_loop(data.mlx_ptr);
}

int     plot_line_low(int start_x, int start_y, int end_x, int end_y, void *param)
{
    int dx, dy, D, yi, x, y;
    s_data  *data;

    data = (s_data *)param;
    dx = end_x - start_x;
    dy = end_y - start_y;
    yi = 1;
    if (dy < 0)
    {
        yi = -1;
        dy = -dy;
    }
    D = 2 * dy - dx;
    y = start_y;
    x = start_x;
    while(x <= end_x)
    {
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xFFFFFF);
        if(D >= 0)
        {
            y = y + yi;
            D = D - 2 * dx;
        }
        D = D + 2 * dy;
        x = x + 1;
    }
    return (0);
}

int     plot_line_high(int start_x, int start_y, int end_x, int end_y, void *param)
{
    int dx, dy, D, yi, x, y,xi;
    s_data  *data;

    data = (s_data *)param;
    dx = end_x - start_x;
    dy = end_y - start_y;
    xi = 1;
    if (dx < 0)
    {
        xi = -1;
        dx = -dx;
    }
    D = 2 * dx - dy;
    y = start_y;
    x = start_x;
    while(y <= end_y)
    {
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xFFFFFF);
        if(D >= 0)
        {
            x = x + xi;
            D = D - 2 * dy;
        }
        D = D + 2 * dx;
        y = y + 1;
    }
    return (0);
}

int     plotLine(int start_x, int start_y, int end_x, int end_y, void *param)
{
    if (abs(end_y - start_y) < abs(end_x - start_x))
    {
        if (start_x > end_x)
            plot_line_low(end_x, end_y, start_x, start_y, param);
        else
            plot_line_low(start_x, start_y, end_x, end_y, param);
    }
    else
    {
        if (start_y > end_y)
            plot_line_high(end_x, end_y, start_x, start_y, param);
        else
            plot_line_high(start_x, start_y, end_x, end_y, param);
    }
    return (0);
}