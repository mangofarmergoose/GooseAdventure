#include <iostream>
#include "board.hpp"
#include "card.hpp"
#include "control.hpp"
//Column: 0,1,21,22; Row: 0,1,2,14,15,16

static CardTypes cardtype;
static Cards card;

void InitCard(){
    card.status = Selecting;
    card.location.x = 10;
    card.location.y = 10;
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
            std::cout << GetColumn(card.location.x)<< " "<< GetRow(card.location.y) <<std::endl;
        }
        if(IsKeyPressed(KEY_A) && board[NextLeftX][GetRow(card.location.y)].status == Card){
            card.location.x -= 35;
            
            std::cout << GetColumn(card.location.x)<< " "<< GetRow(card.location.y) <<std::endl;
        }
        if(IsKeyPressed(KEY_W) && board[GetColumn(card.location.x)][NextUpY].status == Card){
            card.location.y -= 35;
            std::cout << GetColumn(card.location.x)<< " "<< GetRow(card.location.y) <<std::endl;
        }
        if(IsKeyPressed(KEY_S) && board[GetColumn(card.location.x)][NextDownY].status == Card){
            card.location.y += 35;
            std::cout << GetColumn(card.location.x)<< " "<< GetRow(card.location.y) <<std::endl;
        }
    }
}

void DrawCard(){
}

void CheckCardGrid(){

}