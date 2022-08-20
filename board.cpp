#include <iostream>
#include <raylib.h>
#include "board.hpp"

using namespace std;

void InitBoard(){
	//Init Board
	cout << VERTICAL_OFFSET << endl;
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

void CheckGrid(){
	for (int i=0; i<COLUMNS; ++i){
		for (int j=0; j<ROWS; ++j){
			if(i>=2 && i<=20 && j>=3 && j<=13){
				//Player and Board
				if(CheckCollisionRecs(player.location, board[i][j].outerRect)){
					board[i][j].status = Main;
				}else{
					board[i][j].status = Empty;
				}
			}
		}
	}
}


void Move(){

		if(IsKeyPressed(KEY_RIGHT) && player.location.x < screenWidth-GRIDSIZE){
			player.location.x += GRIDSIZE+5;
		}
		if(IsKeyPressed(KEY_LEFT) && player.location.x > 0){
			player.location.x -= GRIDSIZE+5;
		}
		if(IsKeyPressed(KEY_UP) && player.location.y > VERTICAL_OFFSET){
			player.location.y -= GRIDSIZE+5;
			cout << GetScreenHeight() - VERTICAL_OFFSET << endl;
		}
		if(IsKeyPressed(KEY_DOWN) && player.location.y < screenHeight-GRIDSIZE-VERTICAL_OFFSET){
			player.location.y += GRIDSIZE+5;
		}
}
