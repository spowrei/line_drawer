#include "PixelGrid.hpp"

void set_px_pos(sf::VertexArray &vx_arr)
{
	for (int i = 0; i < PX_COUNT_X * PX_COUNT_Y; i++)
	{
		int x = (i % PX_COUNT_X) * PX_SIZE;
		int y = (i / PX_COUNT_X) * PX_SIZE;
		int vi = i * 4;

		vx_arr[vi + 0].position = sf::Vector2f(x, y);
		vx_arr[vi + 1].position = sf::Vector2f(x + PX_SIZE, y);
		vx_arr[vi + 2].position = sf::Vector2f(x + PX_SIZE, y + PX_SIZE);
		vx_arr[vi + 3].position = sf::Vector2f(x, y + PX_SIZE);

		for (int j = 0; j < 4; j++)
			vx_arr[vi + j].color = DEFAULT_COLOR_1;
	}
}

int mousepos_to_index(sf::Vector2i v)
{
	int px = v.x / PX_SIZE;
	int py = v.y / PX_SIZE;
	return px + py * PX_COUNT_X;
}

void index_to_quads(sf::VertexArray *vertex_arr, int index, void (*func)(sf::VertexArray *vertex_arr, int quad_index))
{
	for (int i = 0; i < 4; i++)
	{
		func(vertex_arr, index * 4 + i);
	}
}

void paint_quads(sf::VertexArray *vertex_arr, int quad_index)
{
	(*vertex_arr)[quad_index].color = DEFAULT_COLOR_2;
}
