//
// Created by Leto Vania on 24/10/2019.
//

#include "fdf.h"

void    map_draw(void *param)
{
    int x;
    int y;
    s_data *data;
    s_point ***points;

    data = (s_data *)param;
    points = data->matrix;
    y = 0;
    x = 0;
    while (x < 10)
    {
        y = 0;
        while (y < 10)
        {
            printf("%f\t %f", points[x][y]->x * 30 + WINHEIGHT/2, points[x][y]->y * 30 + WINWIDTH/2);
            if ( x + 1 < 10) {
                plotLine(points[x][y]->x * 30 + WINHEIGHT/2, points[x][y]->y * 30 + WINWIDTH/2, points[x + 1][y]->x * 30 + WINHEIGHT/2, points[x + 1][y]->y * 30 + WINWIDTH/2,(void *)(&data));
            }
            if (y + 1 < 10) {
                plotLine(points[x][y]->x * 30 + WINHEIGHT/2, points[x][y]->y * 30 + WINWIDTH/2, points[x][y + 1]->x * 30 + WINHEIGHT/2, points[x][y + 1]->y * 30 + WINWIDTH/2,(void *)(&data));
            }
            y++;
        }
        x++;
    }
}