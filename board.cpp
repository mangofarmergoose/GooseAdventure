#include <iostream>
#include "board.hpp"


Grid board[COLUMNS][ROWS];
Outcomes outcomes;
Player player;

void InitBoard(){
	//Init Board
	for (int i=0; i< COLUMNS; ++i){
		for (int j=0; j< ROWS; ++j){
			board[i][j].grid.height = GRIDSIZE;
			board[i][j].grid.width = GRIDSIZE;
			board[i][j].grid.x = i*(GRIDSIZE + 5);
			board[i][j].grid.y = j*(GRIDSIZE + 5) + VERTICAL_OFFSET;
			if(i<2 || i>20 || j<3 || j>13){
				board[i][j].status = Card;
			}else{
				board[i][j].status = Empty;
			}
		}
	}
	std::cout << board[0][0].status << std::endl;
}

void DrawBoard(){
	for (int i=0; i< COLUMNS; ++i){
		for (int j=0; j< ROWS; ++j){
			if(board[i][j].status == Empty){
				DrawRectangleRec(board[i][j].grid, GRAY);	
			}else if(board[i][j].status == Main){
				DrawRectangleRec(board[i][j].grid, RED);
			}else if(board[i][j].status == Card){
				DrawRectangleRec(board[i][j].grid, DARKGRAY);
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

//Check Collision
void CheckInnerGrid()
{
	for (int i = 0; i < COLUMNS; ++i)
	{
		for (int j = 0; j < ROWS; ++j)
		{
			if (board[i][j].status != Card)
			{
				// Inner Board
				if (CheckCollisionRecs(player.location, board[i][j].grid))
				{
					board[i][j].status = Main;
				}
				else
				{
					board[i][j].status = Empty;
				}
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
