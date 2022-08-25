#ifndef CONTROL
#define CONTROL

#include "raylib.h"

#define screenWidth 800
#define screenHeight 600
#define GRIDSIZE 30
#define COLUMNS 23
#define ROWS 17
#define VERTICAL_OFFSET 5

int GetRow(float y);
int GetColumn(float x);

#endif