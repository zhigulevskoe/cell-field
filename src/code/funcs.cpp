#include "../headers/include.h"

#include <iostream>
#include <vector>

// render game field. every cell is empty by default, but to be more understandable, if cell.get_face() return empty string, the function will print EMPTY_CELL string
void render_field (std::vector<std::vector<Cell>> field)
{
    for (auto& rows : field)
    {
        for (auto& cell : rows)
        {
            if (cell.get_face() == "")
            {
                std::cout << EMPTY_CELL << ' ';
            }
            else std::cout << cell.get_face() << ' ';
            
        }
        std::cout << '\n';
    }
}