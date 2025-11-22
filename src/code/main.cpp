// #include "../headers/include.h"
#include <chrono>

#include "../headers/classes.h"
#include "../headers/const.h"
#include "../headers/funcs.h"

#include <iostream>
#include <vector>

using namespace std;



int main ()
{
    vector<vector<Cell>> game_field (ROWS_Y, vector<Cell> (COLS_X));

    // game_field[0][0].Cell('p');

    // ==================== OBJECT CREATING SECTION ====================
    Entity DAMN = Entity("D", true, 5, 5);  // player object

    Entity ent = Entity("E", true, 2, 2);

    // ==================== SPAWN SECTION ====================
    spawn (game_field, ent);
    spawn (game_field, DAMN);

    ent.move_to(game_field, ent.get_x()+1, ent.get_y()+1);


    // TODO: replace this section with more efficient
    bool exit_flag = false;
    char next_move {};

    // main process cycle
    while (!exit_flag)
    {
        clean_screen();
        // render_field(game_field);
        render(game_field);
        // measure_time(render, game_field);

        printf("Next move: ");
        scanf("%c", &next_move);

        switch (next_move)
        {
            case 'q':
            {
                printf("Exiting...\n");
                exit_flag = true;
                break;
            }
            
            case 'j':
            {
                uint jmp_x {0}, jmp_y {0};
                printf("Enter coords (x, y): ");
                scanf("%u %u", &jmp_x, &jmp_y);

                DAMN.move_to(game_field, jmp_x + 1, jmp_y + 1);
                break;
            }

            // case 'e': {
            //     Y += 5;
            //     break;
            // }
            
            default:
            {
                printf("Invalid command\n");
                break;
            }
        }

        if (!exit_flag)
        {
            printf("\n===== DEBUG INFO =====\n");

            // printf("%d %d", 17 % 10, 20 % 10);

            printf("======================\n");

            printf("\nPress Enter to continue...");
            cin.ignore();
            cin.get();
        }
    }

    return 0;
}

