#pragma once

#include "const.h"
// #include "funcs.h"

#include <string>

class Cell
{
    public:
        Cell();
        Cell(std::string face);
        // void generate_field (uint x, uint y);
        void print_face ();
        std::string get_face ();
        void set_face (std::string symbol);

    private:
        // uint x, y;
        std::string face;
};
