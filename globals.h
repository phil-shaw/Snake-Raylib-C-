#ifndef GLOBALS_H
#define GLOBALS_H

const int screenWidth = 800;
const int screenHeight = 800;
const int grid_size = 20;
bool gane_over = false;
int score = 0;

#include <stdlib.h>
#include <iostream>
#include <vector>
#include "ctime"

#include "raylib.h"
#include "raymath.h"

#include "snake.h"
#include "food.h"

enum class State { g_start, g_play, g_paused, g_end };
State game_state = State::g_start;
Snake s;
Food f;


#endif