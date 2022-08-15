#include <iostream>
#include <raylib.h>
#include <board.hpp>

using namespace std;

static Grid board[COLUMNS][ROWS]; 
static Player player;
static Outcomes outcomes;

void InitBoard(){
	//Init Board
	double offset_y = 600 - (GRIDSIZE + 5)* ROWS;
	for (int i=0; i< COLUMNS; ++i){
		for (int j=0; j< ROWS; ++j){
			board[i][j].outerRect.height = GRIDSIZE;
			board[i][j].outerRect.width = GRIDSIZE;
			board[i][j].outerRect.x = i*(GRIDSIZE + 5);
			board[i][j].outerRect.y = j*(GRIDSIZE + 5) + offset_y;

			board[i][j].status = 0;
		}
	}
}

void DrawBoard(){
	for (int i=0; i< COLUMNS; ++i){
		for (int j=0; j< ROWS; ++j){
			if(board[i][j].status == 0){
				DrawRectangleRec(board[i][j].outerRect, GRAY);	
			}else if(board[i][j].status == 1){
				DrawRectangleRec(board[i][j].outerRect, RED);
			}
		}
	}
}

void InitPlayer(){
	double offset_y = 600 - (GRIDSIZE + 5)* ROWS;
	player.location.width = GRIDSIZE;
	player.location.height = GRIDSIZE;
	player.location.x = COLUMNS/2 * (GRIDSIZE+5);
	player.location.y = ROWS/2 * (GRIDSIZE+5) + offset_y;
}

void CheckGrid(){
	for (int i=0; i<COLUMNS; ++i){
		for (int j=0; j<ROWS; ++j){
			
			//Player and Board
			if(CheckCollisionRecs(player.location, board[i][j].outerRect)){
				board[i][j].status = Main;
			}else{
				board[i][j].status = Empty;
			}
		}
	}
}

void Move(){
		if(IsKeyPressed(KEY_RIGHT)){
		player.location.x += GRIDSIZE+5;
		}
		if(IsKeyPressed(KEY_LEFT)){
			player.location.x -= GRIDSIZE+5;
		}
		if(IsKeyPressed(KEY_UP)){
			player.location.y -= GRIDSIZE+5;
		}
		if(IsKeyPressed(KEY_DOWN)){
			player.location.y += GRIDSIZE+5;
		}
	
	cout << player.location.x << " " << player.location.y << endl;
}