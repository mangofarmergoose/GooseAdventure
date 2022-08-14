#ifndef BOARD
#define BOARD

#include <raylib.h>

using namespace std;

#define screenWidth 800
#define screenHeight 600
#define GRIDSIZE 30
#define COLUMNS 23
#define ROWS 17

void InitBoard();
void DrawBoard();

struct Grid{
    Rectangle outerRect;
    bool isEmpty;
};
#endif