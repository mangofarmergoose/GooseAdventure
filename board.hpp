#ifndef BOARD_HPP
#define BOARD_HPP
#include <iostream>
#include "control.hpp"


void InitBoard();
void DrawBoard();
void Move();
void InitPlayer();
void CheckInnerGrid();

struct Grid{
    Rectangle grid;
    int status;
    
};

enum Outcomes{
    Empty = 0,
    Main = 1,
    Mob = 2,
    Card = 3
};

struct Player{
    Rectangle location;
};

extern Grid board[COLUMNS][ROWS];
extern Outcomes outcomes;
extern Player player;

#endif
