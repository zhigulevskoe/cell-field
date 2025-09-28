#include "../headers/classes.h"
#include "../headers/const.h"

#include <iostream>
#include <vector>

using namespace std;

int main ()
{

    vector<vector<Cell>> game_field (ROWS, vector<Cell> (COLS));

    for (auto& rows : game_field)
    {
        for (auto& cell : rows)
        {
            cell.set_face(EMPTY_CELL);
            cout << cell.get_face() << ' ';
        }
        cout << '\n';
    }
    
    // for (auto& rows : game_field)
    // {
    //     for (auto& cell : rows)
    //     {
    //         cout << cell.get_face() << ' ';
    //     }
    //     cout << '\n';
    // }

    return 0;
}