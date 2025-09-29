// #include "../headers/include.h"
#include "../headers/classes.h"
#include "../headers/const.h"
#include "../headers/funcs.h"

#include <iostream>
#include <vector>

using namespace std;

int main ()
{
    vector<vector<Cell>> game_field (ROWS, vector<Cell> (COLS));

    game_field[0][0].set_face("P");

    // render_field(game_field);

    Item item = Item("I");

    cout << item.get_face() << endl;

    return 0;
}