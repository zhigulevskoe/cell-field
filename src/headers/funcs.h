#pragma once

#include "classes.h"

#include <string>
#include <vector>

void render_field (std::vector<std::vector<Cell>> field);
void render (std::vector<std::vector<Cell>> &field);
void clean_screen();
void spawn (std::vector<std::vector<Cell>> &field, Cell &object);
// void process();
// auto measure_time