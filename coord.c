//
// Created by Leto Vania on 20/10/2019.
//

#include "fdf.h"

s_point *create_point(int x, int y, int z)
{
    s_point *point;

    point = (s_point *)malloc(sizeof(s_point));
    point->x = x;
    point->y = y;
    point->z = z;
    point->x_p = x;
    point->y_p = y;
    point->z_p = z;
    point->next = NULL;
    return (point);
}

s_point ***matrix(void)
{
    s_point ***points;
    s_point *point;
    int i;


    i = 0;
    points = (s_point ***)malloc(sizeof(s_point**) * 10);
    while (i < 10) {
        points[i] = (s_point **) malloc(sizeof(s_point*) * 10);
        i++;
    }
    return (points);
}