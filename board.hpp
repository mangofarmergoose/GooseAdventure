#ifndef BOARD_HPP
#define BOARD_HPP
#include <iostream>
#include "control.hpp"


void InitBoard();
void DrawBoard();
void Move();
void InitPlayer();
void CheckGrid();

struct Grid{
    Rectangle grid;
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

struct Player{
    Rectangle location;
};

static Player player;




#endif
