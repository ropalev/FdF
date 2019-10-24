//
// Created by Leto Vania on 20/10/2019.
//
#include "fdf.h"
#include <fcntl.h>

s_point     *parser(char *file)
{
    int     fd;
    char    *line;
    char    **s;
    int     x;
    int     y;
    s_point *head;


    y = 0;
    fd = open(file, O_RDONLY);
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
    return (head);
}