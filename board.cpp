#include <iostream>
#include <raylib.h>

using namespace std;

#define GRIDSIZE 30
#define COLUMNS 23
#define ROWS 17

void InitBoard();
void DrawBoard();

struct Grid{
    Rectangle outerRect;
    bool isEmpty;
};

Grid board[COLUMNS][ROWS];

void InitBoard(){
	//Init Board
	double offset_y = 600 - (GRIDSIZE + 5)* ROWS;
	cout << offset_y << endl;
	for (int i=0; i< COLUMNS; ++i){
		for (int j=0; j< ROWS; ++j){
			board[i][j].outerRect.height = GRIDSIZE;
			board[i][j].outerRect.width = GRIDSIZE;
			board[i][j].outerRect.x = i*(GRIDSIZE + 5);
			board[i][j].outerRect.y = j*(GRIDSIZE + 5) + offset_y;

			board[i][j].isEmpty = true;
		}
	}
}

void DrawBoard(){
	for (int i=0; i< COLUMNS; ++i){
		for (int j=0; j< ROWS; ++j){
			DrawRectangleRec(board[i][j].outerRect, GRAY);
		}
	}
}