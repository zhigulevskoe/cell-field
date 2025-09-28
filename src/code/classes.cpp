#include "../headers/classes.h"
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
    std::cout << face << std::endl;
}

std::string Cell::get_face ()
{
    return face;
}