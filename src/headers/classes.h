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

class Item : public Cell
{
    public:
        Item();
        Item(std::string face);
};

class Entity : public Item
{
    public:
        Entity();
        Entity(std::string face);
        Entity(std::string face, bool mayCollide);
        
        void set_collision (bool collision);
        bool get_collision ();
    
    private:
        bool mayCollide = false;
};