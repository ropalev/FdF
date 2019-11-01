//
// Created by Leto Vania on 20/10/2019.
//
#include "fdf.h"



s_point ***matrix(int width, int height)
{
    s_point ***points;
    s_point *point;
    int i;


    i = 0;
    points = (s_point ***)malloc(sizeof(s_point**) * height);
    while (i < height) {
        points[i] = (s_point **) malloc(sizeof(s_point*) * width);
        i++;
    }
    return (points);
}

int     check_map(char *file_name, s_data *data)
{
    char    **str;
    int     len;
    int     fd;
    char    *line;
    int     res;
    data->height = 0;
    data->width = 0;
    fd = open(file_name, O_RDONLY);
    while ((get_next_line(fd, &line)) == 1)
    {
        len = 0;
        str = ft_strsplit(line, ' ');
        while (*str++)
            len++;
        if (data->width == 0)
            data->width = len;
        else if (data->width != len)
            printf("error");
        data->height += 1;
    }
	data->par_scale = (WINHEIGHT < WINWIDTH ? WINHEIGHT : WINWIDTH) /
					  (data->height > data->width ? data->height : data->width);
}

void    parser(char *file,s_data *data)
{
    int fd;
    int y;
    int x;
    char *line;
    char **s;

    y = 0;
    fd = open(file, O_RDONLY);
    while ((get_next_line(fd, &line)) > 0) {
        s = ft_strsplit(line, ' ');
        x = 0;
        while (*s) {
            data->matrix[y][x] = create_point(x - data->width/2, y - data->height/2, ft_atoi(*s));
            s++;
            x++;
        }
        y++;
    }
    data->color = 0xA1A1A1;
    close(fd);
};