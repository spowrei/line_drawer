#include "ShapeDrawer.hpp"
#include <iostream> //! !!!!!!!!!!!!!!!!!!sil

static int index_giver(int y, int x, int z)
{
	int pos_x = OFFSET + (x + y) * 0.86 * SHAPE_BASE;
	int pos_y = OFFSET + y * 0.5 * SHAPE_BASE - (x - y) * 0.5 * SHAPE_BASE - z * SHAPE_HEIGHT;
	return (pos_x + PX_COUNT_X * pos_y);
}

void draw_shape(sf::VertexArray *vertex_arr)
{
	int matris[7][7] = {
	{0,1,2,3,2,1,0},
	{0,1,2,3,2,1,0},
	{0,1,2,3,2,1,0},
	{0,1,2,3,2,1,0},
	{0,1,2,3,2,1,0},
	{0,1,2,3,2,1,0},
	{0,1,2,3,2,1,0}
	};


	std::cout << "a\n";
	for (int y = 0; y < 7; y++)
	{
		for (int x = 0; x < 7; x++)
		{
			if (y < 6)
				draw_the_line(vertex_arr, index_giver(y, x, matris[y][x]), index_giver(y + 1, x, matris[y+1][x]));
			if (x < 6)
				draw_the_line(vertex_arr, index_giver(y, x, matris[y][x]), index_giver(y, x + 1, matris[y][x+1]));
		}
	}
	std::cout << "b\n";
}
