#include "Food.h"

Food::Food(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;

    this-> foodPos = objPos();
}

Food::~Food()
{
    
}

void Food::generateFood(objPos blockOff)
{
    do {
        foodPos.pos->x = rand() % (mainGameMechsRef->getBoardSizeX() - 2) + 1;
        foodPos.pos->y = rand() % (mainGameMechsRef->getBoardSizeY() - 2) + 1;
    } while (foodPos.pos->x == blockOff.pos->x && foodPos.pos->y == blockOff.pos->y);
}

objPos Food::getFoodPos() const
{
    return foodPos;
}

