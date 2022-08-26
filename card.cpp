#include <iostream>
#include <raylib.h>
#include "board.hpp"
#include "card.hpp"
#include "control.hpp"
//Column: 0,1,21,22; Row: 0,1,2,14,15,16

CardTypes cardtypes;
Cards card;

void InitCard(){
    card.location.x = 10;
    card.location.y = 10;
    card.enterPlacement = false;
    card.isSelecting = false;
}

void PlaceCard(){
    if(IsKeyDown(KEY_ENTER)){
        card.enterPlacement = true;
    }

    if(IsKeyDown(KEY_Q)){
        card.enterPlacement = false;
    }

    if(card.enterPlacement == true){

        int NextRightX = GetColumn(card.location.x + 35);
        int NextLeftX = GetColumn(card.location.x - 35);
        int NextUpY = GetRow(card.location.y - 35);
        int NextDownY = GetRow(card.location.y + 35);

        if(IsKeyPressed(KEY_D) && board[NextRightX][GetRow(card.location.y)].status == Card) {
            card.location.x += 35;
        }

        if(IsKeyPressed(KEY_A) && board[NextLeftX][GetRow(card.location.y)].status == Card){
            card.location.x -= 35;
        }

        if(IsKeyPressed(KEY_W) && board[GetColumn(card.location.x)][NextUpY].status == Card){
            card.location.y -= 35;
        }

        if(IsKeyPressed(KEY_S) && board[GetColumn(card.location.x)][NextDownY].status == Card){
            card.location.y += 35;
        }
    }
}

void DrawCard(){
    for (int c=0; c<COLUMNS; ++c){
        for (int r=0; r<ROWS; ++r){
            if(board[c][r].status == Card){
                DrawRectangleRec(board[c][r].grid, board[c][r].color);
            }
        }
    }
}

void CheckCardGrid(){
    for(int i=0; i<COLUMNS; ++i){
        for(int j=0; j<ROWS; ++j){

            if(board[i][j].status == Card && card.enterPlacement){

                int c = GetColumn(card.location.x);
                int r = GetRow(card.location.y);



                if(CheckCollisionPointRec(card.location, board[i][j].grid)){
                    std::cout << "test" << std::endl;
                    board[c][r].card_status = Selecting;
                    board[c][r].color = GREEN;
                }else if(IsKeyPressed(KEY_Z)){
                    board[c][r].card_status = Barrack;
                    board[c][r].color = BROWN;
                }else if(IsKeyPressed((KEY_X))){
                    board[c][r].card_status = Forge;
                    board[c][r].color = LIME;
                }else if(IsKeyPressed((KEY_C))){
                    board[c][r].card_status = Shelter;
                    board[c][r].color = ORANGE;
                }

                //Remove selection trail. Turn card tile to blue while selecting.
                else{
                    board[i][j].card_status = Default;
                    board[i][j].color = BLUE;
                }

            }
        }
    }
}
