// #include "../headers/include.h"

#include "../headers/classes.h"
#include "../headers/const.h"
#include "../headers/funcs.h"

#include <string>
#include <iostream>

Cell::Cell () { }

Cell::Cell (std::string face)
{
    this->face = face;
}



void Cell::set_face (std::string symbol)
{
    face = symbol;
}

void Cell::print_face ()
{
    std::cout << face;
}

std::string Cell::get_face ()
{
    return face;
}



Item::Item ()
{   }

Item::Item (std::string face) : Cell (face)
{   }



Entity::Entity ()
{   }

Entity::Entity (std::string face) : Item (face)
{   }

Entity::Entity (std::string face, bool mayCollide) : Entity (face)
{
    this->mayCollide = mayCollide;
}

void Entity::set_collision (bool collision)
{
    mayCollide = collision;
}

bool Entity::get_collision ()
{
    return mayCollide;
}
