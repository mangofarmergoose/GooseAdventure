#include "raylib.h"

struct Cards
{
    Vector2 location;
    bool enterPlacement; //Enter card placement mode
    bool isSelecting;
};

extern Cards card;

void InitCard();
void PlaceCard();
void CheckCardGrid();
void DrawCard();
