#include <iostream>
#include "card.hpp"
#include "control.hpp"
//Column: 0,1,21,22; Row: 0,1,2,14,15,16

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
        if(IsKeyPressed(KEY_D)) {
            card.location.x += 35;
            std::cout << card.location.x << std::endl;
        }
        if(IsKeyPressed(KEY_A)){
            card.location.x -= 35;
            std::cout << "left" << std::endl;
        }
        if(IsKeyPressed(KEY_W)){
            card.location.y -= 35;
            std::cout << "up" << std::endl;
        }
        if(IsKeyPressed(KEY_S)){
            card.location.y += 35;
            std::cout << "down" << std::endl;
        }
    }
}

void DrawCard(){
}