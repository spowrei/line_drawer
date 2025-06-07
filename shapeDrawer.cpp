#include "ShapeDrawer.hpp"
#include <iostream> //! !!!!!!!!!!!!!!!!!!sil

static int index_giver(int y, int x)
{
	std::cout << (OFFSET + SHAPE_SIZE * x + (OFFSET + SHAPE_SIZE * y) * PX_COUNT_X) << std::endl;
	return (OFFSET + SHAPE_SIZE * x + (OFFSET + SHAPE_SIZE * y) * PX_COUNT_X);
}

void draw_straight_line(sf::VertexArray *vertex_arr)
{
	bool matris[4][4] = {1,1,1,0,
						1,0,1,1,
						1,0,1,1,
						1,1,1,0};

	std::cout << "a\n";
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			std::cout << index_giver(y, x) << "\n";
			if (y < 3)
				if (matris[y][x] && matris[y + 1][x])
					draw_the_line(vertex_arr, index_giver(y, x), index_giver(y + 1, x));
			if (x < 3)
				if (matris[y][x] && matris[y][x + 1])
					draw_the_line(vertex_arr, index_giver(y, x), index_giver(y, x + 1));
		}
	}
	std::cout << "b\n";
}
