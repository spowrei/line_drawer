#include "LineDrawer.hpp"
#include <cmath>

void draw_the_line(sf::VertexArray *vertex_arr, int begin_index, int end_index)
{
    int x1 = begin_index % PX_COUNT_X;
    int y1 = begin_index / PX_COUNT_X;
    int x2 = end_index % PX_COUNT_X;
    int y2 = end_index / PX_COUNT_X;
    int len_x = abs(x2 - x1);
    int len_y = abs(y2 - y1);
    int direction_x = (x1 < x2) ? 1 : -1;
    int direction_y = (y1 < y2) ? 1 : -1;
    int err = len_x - len_y;
    
    while (1)
    {
        index_to_quads(vertex_arr, x1 + y1 * PX_COUNT_X, paint_quads);

        if (x1 == x2 && y1 == y2)
            break;

        int e2 = 2 * err;
        if (e2 > -len_y)
        {
            err -= len_y;
            x1 += direction_x;
        }
        if (e2 < len_x)
        {
            err += len_x;
            y1 += direction_y;
        }
    }
}

