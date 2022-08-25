#ifndef BOARD
#define BOARD
#include <iostream>
#include "control.hpp"


void InitBoard();
void DrawBoard();
void Move();
void InitPlayer();
void CheckGrid();



struct Player{
    Rectangle location;
};

static Player player;




#endif
