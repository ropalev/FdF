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

    s_data *data;
    s_point ***points;

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
int   plot(int x, int y, void *param)
{
    if ((0 < y && y < WINWIDTH) && (0 < x && x < WINHEIGHT))
        plotLine(WINHEIGHT/2,WINWIDTH/2, x, y, param);
    return (0);
}

int     main(int argc, char **argv) {
    s_data data;
    int y;
    int fd;
    int x;
    char *line;
    char **s;
    s_point ***points;

    data.matrix = matrix();
    y = 0;
    fd = open(argv[1], O_RDONLY);
    while ((get_next_line(fd, &line)) > 0) {
        s = ft_strsplit(line, ' ');
        x = 0;
        while (*s) {
            data.matrix[y][x] = create_point((x - 4.5), (y - 4.5), ft_atoi(*s));
            s++;
            x++;
        }
        y++;
    }
    close(fd);

    data.mlx_ptr = mlx_init();
    data.win_ptr = mlx_new_window(data.mlx_ptr, WINHEIGHT, WINWIDTH, "Window");
    //mlx_hook(data.win_ptr, 4, 4, &mouse_action, (void *) (&data));
    mlx_hook(data.win_ptr, 2, 2, &keyboard_action, (void *) (&data));
    mlx_hook(data.win_ptr, 17, 17, &close, (void *) (&data));
    //map_draw((void *) (&data));
    map_iso((void *) (&data));
    mlx_loop(data.mlx_ptr);
}