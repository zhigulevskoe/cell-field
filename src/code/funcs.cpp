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
            if (cell.get_face().empty())
            {
                std::cout << EMPTY_CELL << ' ';
            }
            else std::cout << cell.get_face() << ' ';
            
        }
        std::cout << '\n';
    }
}

// void render(std::vector<std::vector<Cell>> &field) {
//
//     for (size_t y = 0; y < field.size(); y++) {
//         for (size_t x = 0; x < field[y].size(); x++) {
//
//             // установка номера десятка в первую строку/столбец
//             if (!(y % 10) && !(x % 10)) {
//                 field[y + 1][0].set_face(std::to_string((y / 10) % 10));
//                 field[y + 1][0].set_collision(true);
//                 field[0][x + 1].set_face(std::to_string((x / 10) % 10));
//                 field[0][x + 1].set_collision(true);
//             }
//
//             field[y][1].set_face(std::to_string((y - 1) % 10));
//             field[y][1].set_collision(true);
//
//             field[1][x].set_face(std::to_string((x - 1) % 10));
//             field[1][x].set_collision(true);
//
//             field[0][1].set_face(std::to_string(0));
//             field[1][0].set_face(std::to_string(0));
//
//             if (field[y][x].get_face().empty()) {
//                 std::cout << EMPTY_CELL << ' ';
//             }
//             else std::cout << field[y][x].get_face() << ' ';
//
//         }
//         std::cout << '\n';
//     }
// }

// void render(std::vector<std::vector<Cell>> &field) {
//
//     for (size_t y = 0; y < field.size(); y++) {
//         for (size_t x = 0; x < field[y].size(); x++) {
//
//             // установка номера десятка в первую строку/столбец
//             if (!(y % 10) && !(x % 10)) {
//                 field[y + 1][0].set_face(std::to_string((y / 10) % 10));
//                 field[y + 1][0].set_collision(true);
//                 field[0][x + 1].set_face(std::to_string((x / 10) % 10));
//                 field[0][x + 1].set_collision(true);
//             }
//
//             field[y][1].set_face(std::to_string((y - 1) % 10));
//             field[y][1].set_collision(true);
//
//             field[1][x].set_face(std::to_string((x - 1) % 10));
//             field[1][x].set_collision(true);
//
//             field[0][1].set_face(std::to_string(0));
//             field[1][0].set_face(std::to_string(0));
//
//             if (field[y][x].get_face().empty()) {
//                 std::cout << EMPTY_CELL << ' ';
//             }
//             else std::cout << field[y][x].get_face() << ' ';
//
//         }
//         std::cout << '\n';
//     }
// }
void render(std::vector<std::vector<Cell>>& field) {
    if (field.empty()) {
        std::cout << "Field is empty.\n";
        return;
    }

    // --- Предварительная обработка: установка заголовков ---
    // Проверим, достаточно ли размера у поля для установки заголовков
    // Требуется: field.size() >= 2 и field[0].size() >= 2 и field[y].size() >= 2 для строк с индексами >= 1

    size_t min_rows_needed = 2;
    size_t min_cols_needed = 2;

    // Проверим и расширим, если необходимо (или верните ошибку)
    for (auto& row : field) {
        if (row.size() < min_cols_needed) {
            row.resize(min_cols_needed); // Или обработайте ошибку
        }
    }
    if (field.size() < min_rows_needed) {
        field.resize(min_rows_needed);
        field.back().resize(min_cols_needed); // Убедимся, что новая строка тоже имеет мин. кол-во столбцов
    }

    // Установка "0" в фиксированные ячейки
    field[0][1].set_face("0");
    field[0][1].set_collision(true); // Предполагаем, что это нужно
    field[1][0].set_face("0");
    field[1][0].set_collision(true); // Предполагаем, что это нужно

    // Установка меток по оси Y (в столбце 1)
    for (size_t y = 10; y < field.size(); y += 10) { // Начинаем с 10 и шагаем по 10
        if (y + 1 < field.size()) { // Проверяем границу для y+1
            int tens_digit = (y / 10) % 10;
            std::string tens_str = std::to_string(tens_digit);
            field[y + 1][0].set_face(tens_str);
            field[y + 1][0].set_collision(true); // Предполагаем, что это нужно
        }
    }

    // Установка меток по оси X (в строке 1)
    if (!field[1].empty()) { // Проверяем, что строка 1 существует и не пуста
        for (size_t x = 10; x < field[1].size(); x += 10) { // Начинаем с 10 и шагаем по 10
            if (x + 1 < field[0].size()) { // Проверяем границу для x+1 (используем строку 0 как эталон)
                int tens_digit = (x / 10) % 10;
                std::string tens_str = std::to_string(tens_digit);
                field[0][x + 1].set_face(tens_str);
                field[0][x + 1].set_collision(true); // Предполагаем, что это нужно
            }
        }
    }

    // --- Основной цикл отрисовки ---
    for (size_t y = 0; y < field.size(); ++y) {
        for (size_t x = 0; x < field[y].size(); ++x) {
            // Установка номера единицы в строку 1 и столбец 1
            // (Это всё еще внутри цикла, возможно, это и есть основная логика отображения)
            if (y > 0) { // Избегаем изменения field[0][1] снова
                field[y][1].set_face(std::to_string((y - 1) % 10));
                field[y][1].set_collision(true); // Предполагаем, что это нужно
            }
            if (x > 0) { // Избегаем изменения field[1][0] снова
                field[1][x].set_face(std::to_string((x - 1) % 10));
                field[1][x].set_collision(true); // Предполагаем, что это нужно
            }

            // Вывод содержимого ячейки
            if (field[y][x].get_face().empty()) {
                std::cout << EMPTY_CELL << ' ';
            } else {
                std::cout << field[y][x].get_face() << ' ';
            }
        }
        std::cout << '\n';
    }
}

void clean_screen ()
{
    std::cout << "\x1b[2J\x1b[H";
}

void spawn (std::vector<std::vector<Cell>> &field, Cell &object) {
    field[object.get_y()][object.get_x()] = object;
}
