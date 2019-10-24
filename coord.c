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

void	list_push_back(s_point **begin_list, int x, int y, int z)
{
    s_point *last;

    last = *begin_list;
    if (!last)
    {
        *begin_list = create_point(x, y, z);
        return ;
    }
    while (last->next)
        last = last->next;
    last->next = create_point(x, y, z);
}
