#include <iostream>
#include <raylib.h>

using namespace std;

#define GRIDSIZE 30
#define MAXGRIDS 256


const int screenWidth = 800;
const int screenHeight = 600;

void InitGame();
void DrawGame();
void InitBoard();

struct GameState{
	bool isGameOver;
	bool isPause;
};

struct Vertex{
	Vector2 vert_start_position;
	Vector2 vert_end_position;
	Vector2 hor_start_position;
	Vector2 hor_end_position;
};

struct Grid{

	Vertex vertices;
	Vector2 size;
	Color color;
	bool isEmpty;
};

//Declare Global Variables

Grid board[MAXGRIDS] = {0};
GameState gameState;

int main(){
	InitWindow(screenWidth, screenHeight, "Goose");
	InitGame();
	SetTargetFPS(60);
	
	while(!WindowShouldClose()){
		if(gameState.isGameOver){
			//Draw and Update

		}
	}

	CloseWindow();
	return 0;
}


void InitBoard(){
	//Init Board
	Vector2 offset = {screenWidth % GRIDSIZE, screenHeight % GRIDSIZE};
	for (int i=0; i < screenWidth/GRIDSIZE + 1; ++i){
		board[i].vertices.vert_start_position =  (Vector2) {GRIDSIZE*i + offset.x/2, offset.y/2};
		board[i].vertices.vert_end_position = (Vector2) {GRIDSIZE*i + offset.x/2, screenHeight - offset.y/2};
	}
	for (int i=0; i < screenHeight/GRIDSIZE + 1; ++i){
		board[i].vertices.hor_start_position = (Vector2) {offset.x/2, GRIDSIZE*i + offset.y/2};
		board[i].vertices.hor_end_position = (Vector2) {screenWidth - offset.x/2, GRIDSIZE*i + offset.y/2};
	}
	for (int i=0; i< MAXGRIDS; ++i){
		board[i].size = (Vector2) {GRIDSIZE, GRIDSIZE};
		board[i].isEmpty = true;
		board[i].color = LIGHTGRAY;
	}
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
		ClearBackGround(LIME);
		if(!gameState.isGameOver){
			for (int i=0; i< screenWidth/GRIDSIZE; ++i){
				DrawLine(
