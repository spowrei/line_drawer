#ifndef SHAPE_DRAWER_HPP
#define SHAPE_DRAWER_HPP

#define OFFSET 150.f
#define SHAPE_BASE 5.f
#define SHAPE_HEIGHT 1.f

#include "LineDrawer.hpp"
#include <vector>

void draw_shape(sf::VertexArray *vertex_arr, std::vector<int> map, int map_size);

#endif
