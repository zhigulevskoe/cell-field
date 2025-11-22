#pragma once

#include "const.h"
// #include "funcs.h"

#include <string>
#include <vector>

class Cell
{
    public:
        Cell() = default;
        Cell(std::string face, bool mayCollide, uint spawn_x, uint spawn_y);

        void print_face () const;

        void set_face (std::string symbol);
        std::string get_face ();

        void set_collision (bool collision);
        bool get_collision () const;

        void set_x (uint x);
        uint get_x () const;

        void set_y (uint y);
        uint get_y () const;

    protected:
        uint x = 0, y = 0;
        std::string face;
        bool mayCollide = false;
};



class Entity : public Cell
{
    public:
        using Cell::Cell;

        void move_to(std::vector<std::vector<Cell>> &field, uint new_x, uint new_y);
    
    protected:
        // bool mayCollide = false;
};
