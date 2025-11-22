// #include "../headers/include.h"

#include "../headers/classes.h"
#include "../headers/const.h"
#include "../headers/funcs.h"

#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <cstdio>



// ===================== BASE CELL METHODS =====================



// Cell::Cell () = default;

// Cell::Cell (std::string face)
// {
//     this->face = face;
// }


Cell::Cell(std::string face, const bool mayCollide, const uint spawn_x, const uint spawn_y)
        : x(spawn_x),
          y(spawn_y),
          face(std::move(face)),
          mayCollide(mayCollide) {

}


// Cell::Cell(std::string face, bool mayCollide) // : face(face), mayCollide(mayCollide)
// {
//     this->face = face;
//     this->mayCollide = mayCollide;
// }


void Cell::set_face (std::string symbol)
{
    face = std::move(symbol);
}


void Cell::print_face () const {
    std::cout << face;
}


std::string Cell::get_face ()
{
    return face;
}


void Cell::set_collision (const bool collision)
{
    mayCollide = collision;
}


bool Cell::get_collision () const
{
    return mayCollide;
}


void Cell::set_x(uint x) {
    this->x = x;
}


void Cell::set_y(uint y) {
    this->y = y;
}


uint Cell::get_x () const {
    return x;
}


uint Cell::get_y () const {
    return y;
}



// ===================== ITEM CELL METHODS =====================



// Item::Item () = default;


// Item::Item (std::string face, bool mayCollide) : Cell (face, mayCollide)
// {   }



// ===================== ENTITY CELL METHODS =====================



// Entity::Entity (std::string face) : Item (face)
// {   }

// Entity::Entity() : Cell(face, mayCollide, x, y) {

// }


// Entity::Entity() : Cell(face, mayCollide, spawn_x, spawn_y) {

// }



// Entity::Entity (std::string face, uint spawn_x, uint spawn_y) : Item (face)
// {
//     this->x = spawn_x;
//     this->y = spawn_y;
// }


// Entity::Entity (std::string face, bool mayCollide) : Item (face, mayCollide)
// {
//     // this->mayCollide = mayCollide;
// }




// void Entity::spawn (std::vector<std::vector<Cell>> &field)
// {
//     field[y][x].set_face(face);
//     field[y][x].set_collision(mayCollide);
//
// }


void Entity::move_to (std::vector<std::vector<Cell>> &field, const uint new_x, const uint new_y)
{
    const auto cell = Cell();

    // cheching for going out of bounds
    if (new_x >= COLS_X || new_y >= ROWS_Y)
    {
        printf("\x1b[31mYou're trying to go out of bounds!!! Aborting\x1b[0m\n");
        return;
    }
    else if (field[new_y][new_x].get_collision())
    {
        printf("Attempt to move %s to non-empty cell!!! Aborting\n", face.c_str());
        return;
    }
    else
    {
        const uint old_x = this->x;
        const uint old_y = this->y;
        
        this->x = new_x;
        this->y = new_y;

        field[old_y][old_x] = cell;
        field[new_y][new_x] = *this;

    }

}
