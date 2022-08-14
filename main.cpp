#include <iostream>
#include <raylib.h>
//current files
#include <board.hpp>
using namespace std;


void InitGame();
void DrawGame();

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
	
	//Init Board
	InitBoard();
}


void DrawGame(){
	BeginDrawing();
		ClearBackground(BLACK);
		if(!gameState.isGameOver){
			DrawBoard();
		}
	EndDrawing();
}
