#include <fcntl.h>
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

    int x = 0;
    int y = 0;

    if (keycode == 0)
        figure_rotation(x,0.5, param);


    return (0);
}
int   plot(int x, int y, void *param)
{
    if ((0 < y && y < WINWIDTH) && (0 < x && x < WINHEIGHT))
        plotLine(WINHEIGHT/2,WINWIDTH/2, x, y, param);
    return (0);
}

int     main(int argc, char **argv)
{
    s_data  data;
	s_mouse mouse;
	s_point *head;
	s_point *next;
	s_point *next_x;
    int y,fd,x;
    char *line;
    char **s;
    s_point ***points;

    points = matrix();
    y = 0;
    fd = open(argv[1], O_RDONLY);
    while ((get_next_line(fd, &line)) > 0) {
        s = ft_strsplit(line, ' ');
        x = 0;
        while(*s) {
            points[y][x] = create_point(x, y, ft_atoi(*s));
            s++;
            x++;
        }
        y++;
    }
    close(fd);

    data.matrix = points;
    data.mlx_ptr= mlx_init();
    data.win_ptr = mlx_new_window(data.mlx_ptr, WINHEIGHT, WINWIDTH, "Window");
    mlx_hook(data.win_ptr, 4, 4, &mouse_action, (void *)(&data));
    mlx_hook(data.win_ptr, 6, 6, &plot, (void *)(&data));
    mlx_hook(data.win_ptr, 2, 2, &keyboard_action, (void *)(&data));

    map_draw((void *)(&data));
    /*y = 0;
    x = 0;
    while (x < 10)
    {
        y = 0;
        while (y < 10)
        {
            printf("%d\t %d", points[x][y]->x * 30 + WINHEIGHT/2, points[x][y]->y * 30 + WINWIDTH/2);
            if ( x + 1 < 10) {
                plotLine(points[x][y]->x * 30 + WINHEIGHT/2, points[x][y]->y * 30 + WINWIDTH/2, points[x + 1][y]->x * 30 + WINHEIGHT/2, points[x + 1][y]->y * 30 + WINWIDTH/2,(void *)(&data));
            }
            if (y + 1 < 10) {
                plotLine(points[x][y]->x * 30 + WINHEIGHT/2, points[x][y]->y * 30 + WINWIDTH/2, points[x][y + 1]->x * 30 + WINHEIGHT/2, points[x][y + 1]->y * 30 + WINWIDTH/2,(void *)(&data));
            }
            y++;
        }
        x++;
    }*/
    mlx_loop(data.mlx_ptr);
}
