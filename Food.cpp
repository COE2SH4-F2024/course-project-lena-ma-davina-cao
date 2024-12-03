#include "Food.h"

Food::Food(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    foodPos.pos = new Pos;

    //seed time for more random numbers
    srand(time(NULL));
}

Food::~Food()
{
    delete foodPos.pos;
    foodPos.pos = nullptr;
}

void Food::generateFood(objPosArrayList blockOff)
{
    bool overlap;

    do {
        overlap = false;

        // Generate random coordinates within the board bounds
        foodPos.pos->x = rand() % (mainGameMechsRef->getBoardSizeX() - 2) + 1;
        foodPos.pos->y = rand() % (mainGameMechsRef->getBoardSizeY() - 2) + 1;

        // Check for collisions with positions in blockOffList
        for (int i = 0; i < blockOff.getSize(); i++) {
            const objPos& currentBlock = blockOff.getElement(i);
            if (foodPos.pos->x == currentBlock.pos->x && foodPos.pos->y == currentBlock.pos->y) {
                overlap = true;
                break;
            }
        }
    } while (overlap); // Retry until a non-colliding position is found
}

objPos Food::getFoodPos() const
{
    return foodPos;
}
