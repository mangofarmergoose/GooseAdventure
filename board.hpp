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
void Move();
void InitPlayer(); 
void CheckGrid();

enum Outcomes{
    Empty = 0,
    Main = 1,
    Mob = 2,
    Card = 3
};

struct Grid{
    Rectangle outerRect;
    int status;
};

struct Player{
    Rectangle location;
};

#endif