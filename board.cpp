#include <iostream>
#include "board.hpp"
#include "card.hpp"

void InitBoard(){
	//Init Board
	for (int i=0; i< COLUMNS; ++i){
		for (int j=0; j< ROWS; ++j){
			board[i][j].outerRect.height = GRIDSIZE;
			board[i][j].outerRect.width = GRIDSIZE;
			board[i][j].outerRect.x = i*(GRIDSIZE + 5);
			board[i][j].outerRect.y = j*(GRIDSIZE + 5) + VERTICAL_OFFSET;
			if(i<2 || i>20 || j<3 || j>13){
				board[i][j].status = Card;
			}else{
				board[i][j].status = Empty;
			}
		}
	}
}

void DrawBoard(){
	for (int i=0; i< COLUMNS; ++i){
		for (int j=0; j< ROWS; ++j){
			if(board[i][j].status == Empty){
				DrawRectangleRec(board[i][j].outerRect, GRAY);	
			}else if(board[i][j].status == Main){
				DrawRectangleRec(board[i][j].outerRect, RED);
			}else if(board[i][j].status == Card){
				DrawRectangleRec(board[i][j].outerRect, DARKGRAY);
			}
		}
	}
}

void InitPlayer(){

	player.location.width = GRIDSIZE;
	player.location.height = GRIDSIZE;
	player.location.x = COLUMNS/2 * (GRIDSIZE+5);
	player.location.y = ROWS/2 * (GRIDSIZE+5) + VERTICAL_OFFSET;
	
}

void CheckMovableGridStatus(int c, int r){
	if (CheckCollisionRecs(player.location, board[c][r].outerRect))
	{
		board[c][r].status = Main;
	}
	else
	{
		board[c][r].status = Empty;
	}
} 

void CheckCardGridStatus(int c, int r){
	if(CheckCollisionPointRec(card.location, board[c][r].outerRect)){
	}
}

//Check Collision
void CheckGrid(){
	for (int i=0; i<COLUMNS; ++i){
		for (int j=0; j<ROWS; ++j){
			if(i>=2 && i<=20 && j>=3 && j<=13){
				//Inner Board
				CheckMovableGridStatus(i, j);
			}else{
				//Card Tiles
			}

		}
	}
}




void Move(){
	int rightBound = GetColumn(player.location.x + 35);
    int leftBound = GetColumn(player.location.x - 35);
    int upperBound = GetRow(player.location.y - 35);
    int lowerBound = GetRow(player.location.y + 35);
    // square length 30px + padding 5px
    if (IsKeyPressed(KEY_RIGHT) && rightBound != 21)
    {
        player.location.x += GRIDSIZE + 5;
    }
    if (IsKeyPressed(KEY_LEFT) && leftBound != 1)
    {
        player.location.x -= GRIDSIZE + 5;
    }
    if (IsKeyPressed(KEY_UP) && upperBound != 2)
    {
        player.location.y -= GRIDSIZE + 5;
    }
    if (IsKeyPressed(KEY_DOWN) && lowerBound != 14)
    {
        player.location.y += GRIDSIZE + 5;
    }
}
