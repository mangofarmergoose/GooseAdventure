#include <iostream>
#include "raylib.h"
//current files
#include "board.hpp"
#include "card.hpp"
using namespace std;
void InitGame();
void DrawGame();
void UpdateGame();

struct GameState{
	bool isGameOver;
	bool isPause;
};

//Declare Global Variables
GameState gameState;

int main(){
	InitWindow(screenWidth, screenHeight , "Goose");
	InitGame();
	SetTargetFPS(60);
	
	while(!WindowShouldClose()){
		if(!gameState.isGameOver){
			//Draw and Update
			UpdateGame();
			DrawGame();
		}
	}

	CloseWindow();
	return 0;
}


void InitGame(){
	//Init gameState
	gameState.isGameOver = false;
	gameState.isPause = false;
	
	InitBoard();
	cout << board[3][3].status << endl;
	InitPlayer();
	InitCard();
}

void UpdateGame(){
	CheckGrid();
	Move();
	PlaceCard();
}

void DrawGame(){
	BeginDrawing();
		ClearBackground(BLACK);
		if(!gameState.isGameOver){
			DrawBoard();
		}
	EndDrawing();
}
