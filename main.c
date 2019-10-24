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
    if (keycode == 0)
        exit(0);
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
    int y,fd,x;
    char *line;
    char **s;

    y = 0;
    fd = open(argv[1], O_RDONLY);
    while ((get_next_line(fd, &line)) > 0) {
        s = ft_strsplit(line, ' ');
        x = 0;
        while(*s) {
            printf("%d", ft_atoi(*s));
            list_push_back(&head, x,y, ft_atoi(*s));
            printf(" ");
            s++;
            x++;
        }
        y++;
        printf("\n");
    }
    close(fd);
	//point = parser(argv[1]);
    /*data.mlx_ptr= mlx_init();
    mlx_pixel_put(data.mlx_ptr, data.win_ptr, WINHEIGHT/2,WINWIDTH/2, 0xFFFFFF);
	mlx_hook(data.win_ptr, 4, 4, &mouse_action, (void *)(&data));
    mlx_hook(data.win_ptr, 6, 6, &plot, (void *)(&data));
    mlx_hook(data.win_ptr, 2, 2, &keyboard_action, (void *)(&data));
    mlx_loop(data.mlx_ptr);*/
    while (head)
    {
        printf("%d\t", head->z);
        head = head->next;
    }
}
