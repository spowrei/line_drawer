#include "LineDrawer.hpp"
#include <cmath>

void draw_the_line(sf::VertexArray *vertex_arr, int begin_index, int end_index)
{
	int x1 = begin_index % PX_COUNT_X;
	int y1 = begin_index / PX_COUNT_X;
	int x2 = end_index % PX_COUNT_X;
	int y2 = end_index / PX_COUNT_X;
	int x = x1;
	int y = y1;
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int p = 2 * dy - dx;
	int sx = (x1 > x2) ? -1 : 1;
	int sy = (y1 > y2) ? -1 : 1;

	while (x != x2 + sx)
	{
		index_to_quads(vertex_arr, x + y * PX_COUNT_X, paint_quads);
		x += sx;

		if (p < 0)
		{
			p += 2 * dy;
		}
		else
		{
			p += 2 * (dy - dx);
			y += sy;
		}
	}
}
