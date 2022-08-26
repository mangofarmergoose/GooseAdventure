#ifndef BOARD_HPP
#define BOARD_HPP
#include <iostream>
#include "raylib.h"
#include "control.hpp"


void InitBoard();
void DrawBoard();
void Move();
void InitPlayer();
void CheckInnerGrid();

struct Grid{
    Rectangle grid;
    int status;
    int card_status;
    Color color;
    bool isSelecting;
};

enum Outcomes{
    Empty = 0,
    Main = 1,
    Mob = 2,
    Card = 3
};

enum CardTypes{
    Barrack = 0,
    Forge = 1,
    Shelter = 2,
    Selecting = 3,
    Default = 4
};

struct Player{
    Rectangle location;
};

extern Grid board[COLUMNS][ROWS];
extern Outcomes outcomes;
extern Player player;
extern CardTypes cardtypes;

#endif
