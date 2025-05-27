#ifndef PIXEL_GRID_HPP
#define PIXEL_GRID_HPP

#include <SFML/Graphics.hpp>

#define PX_COUNT_X 90
#define PX_COUNT_Y 60
#define PX_SIZE 10

#define DEFAULT_COLOR_1 sf::Color (100,100,100)
#define DEFAULT_COLOR_2 sf::Color (150,150,150)

void set_px_pos(sf::VertexArray &vx_arr);

int mousepos_to_index(sf::Vector2i v);

void index_to_quads(sf::VertexArray *vertex_arr, int index, void (*func)(sf::VertexArray *vertex_arr, int quad_index));

void paint_quads(sf::VertexArray *vertex_arr, int quad_index);

#endif
#pragma once
