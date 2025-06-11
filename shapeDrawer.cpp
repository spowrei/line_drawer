#include "ShapeDrawer.hpp"
#include <iostream> //! !!!!!!!!!!!!!!!!!!sil

static int index_giver(int y, int x, int z)
{
	int pos_x = OFFSET + (x + y) * 0.86 * SHAPE_BASE;
	int pos_y = OFFSET + y * 0.5 * SHAPE_BASE - (x - y) * 0.5 * SHAPE_BASE - z * SHAPE_HEIGHT;
	return (pos_x + PX_COUNT_X * pos_y);
}

void draw_shape(sf::VertexArray *vertex_arr, std::vector<int> map, int map_size)
{
	std::cout << "a\n";
	for (int y = 0; y < map_size; y++)
	{
		for (int x = 0; x < map_size; x++)
		{
			if (y < map_size - 1)
				draw_the_line(vertex_arr, index_giver(y, x, map[y * map_size + x]), index_giver(y + 1, x, map[(y + 1) * map_size + x]));
			if (x < map_size - 1)
				draw_the_line(vertex_arr, index_giver(y, x, map[y * map_size + x]), index_giver(y, x + 1, map[y * map_size + (x + 1)]));
		}
	}
	std::cout << "b\n";
}
