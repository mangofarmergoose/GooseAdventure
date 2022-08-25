#include "raylib.h"

enum CardTypes{
    Barrack = 0,
    Forge = 1,
    Shelter = 2,
    Selecting = 3,
    Default = 4
};

struct Cards
{
    Vector2 location;
    int status;
    bool enterPlacement; //Enter card placement mode
};

extern CardTypes cardtypes;
extern Cards card;

void InitCard();
void PlaceCard();
void CheckCardGrid();
