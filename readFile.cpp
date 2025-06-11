#include "readFile.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int read_file(std::vector<int> &map)
{
    int map_size = 0;
    std::ifstream file("map.map");
    if (!file.is_open())
    {
        std::cout << "Failed to open file." << std::endl;
        return (-1);
    }

    std::string first_line;
    std::getline(file, first_line);

    std::istringstream iss(first_line);
    std::vector<int> first_row;
    int value;

    while (iss >> value)
    {
        first_row.push_back(value);
    }

    map_size = first_row.size();
    map.reserve(map_size * map_size); 
    map.insert(map.begin(), first_row.begin(), first_row.end());

    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream line_stream(line);
        while (line_stream >> value)
        {
            map.push_back(value);
        }
    }

    file.close();
    return map_size;
}
