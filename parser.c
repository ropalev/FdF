//
// Created by Leto Vania on 20/10/2019.
//
#include "fdf.h"
#include <fcntl.h>

int     main(int args, char **argv)
{
    int     fd;
    char    *line;
    char    **s;

    fd = open(argv[1],O_RDONLY);
    while (get_next_line(fd, &line)) {
        printf("%s", line);
        s = ft_strsplit(line, ' ');
        while(*s) {
            printf("%s", *s);
            s++;
        }
        //ft_strsplit(line, ' ');
        printf("\n");
    }
    //free(line);
    close(fd);
    get_next_line(fd,&line);
    get_next_line(fd,&line);
    //free(line);
    return (0);
}
