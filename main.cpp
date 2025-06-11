#include <SFML/Graphics.hpp>
#include <vector>
#include "LineDrawer.hpp"
#include "ShapeDrawer.hpp"
#include "readFile.hpp"
#include <iostream>

int main()
{
	sf::VertexArray vertex_arr(sf::Quads, PX_COUNT_X * PX_COUNT_Y * 4);
	set_px_pos(vertex_arr);

	std::vector<int> map;
	int map_size = read_file(map);
	std::cout << "ddddd  " << map_size << "  bbbbb\n";

	sf::RenderWindow window(sf::VideoMode(PX_COUNT_X * PX_SIZE, PX_COUNT_Y * PX_SIZE), "PIXELS!", sf::Style::Close);
	window.setFramerateLimit(60);

	draw_shape(&vertex_arr, map, map_size);


	int c_count = -1;
	sf::Vector2i c_pos[2];
	bool c_drawn = true;
	while (window.isOpen())
	{
		window.clear();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				sf::Vector2i m_pos = sf::Mouse::getPosition(window);

				if (m_pos.x >= 0 && m_pos.x <= PX_COUNT_X * PX_SIZE &&
					m_pos.y >= 0 && m_pos.y <= PX_COUNT_Y * PX_SIZE)
				{
					c_count++;
					if (c_count > 1)
						c_count = 0;
					c_pos[c_count] = m_pos;
					c_drawn = false;
				}
			}
		}

		if (c_count == 1)
		{
			draw_the_line(&vertex_arr, mousepos_to_index(c_pos[0]), mousepos_to_index(c_pos[1]));
			c_count++;
		}

		window.draw(vertex_arr);
		window.display();
	}

	return 0;
}
