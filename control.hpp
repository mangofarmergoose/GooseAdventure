#ifndef CONTROL
#define CONTROL

#include "raylib.h"

#define screenWidth 800
#define screenHeight 600
#define GRIDSIZE 30
#define COLUMNS 23
#define ROWS 17
#define VERTICAL_OFFSET 5

struct Grid{
    Rectangle outerRect;
    int status;
};
static Grid board[COLUMNS][ROWS];

enum Outcomes{
    Empty = 0,
    Main = 1,
    Mob = 2,
    Card = 3
};
static Outcomes outcomes;

int GetRow(float y);
int GetColumn(float x);

#endif