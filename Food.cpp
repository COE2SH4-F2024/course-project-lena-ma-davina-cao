//include header file
#include "Food.h"

//default constructor
Food::Food(GameMechs* thisGMRef)
{
    //def. & init. of default values & passed values
    mainGameMechsRef = thisGMRef;
    foodPos.pos->x = 0;
    foodPos.pos->y = 0;
    foodPos.symbol = '@';

    //seed time for more random numbers
    srand(time(NULL));
}

//copy constructor
Food::Food(const Food &f, GameMechs* thisGMRef){
    mainGameMechsRef = thisGMRef;
    foodPos.pos->x = f.foodPos.pos->x;
    foodPos.pos->y = f.foodPos.pos->y;
    foodPos.symbol = f.foodPos.symbol;
    
}

//copy assignment
Food& Food::operator= (const Food &f){
    if (this != nullptr){
        foodPos.pos->x = f.foodPos.pos->x;
        foodPos.pos->y = f.foodPos.pos->y;
        foodPos.symbol = f.foodPos.symbol;
    }
    return *this;
}

//destructor
Food::~Food()
{

}

//generate food using blocked position passed into func.
void Food::generateFood(objPosArrayList* blockOff)
{
    //var. dec.
    bool overlap;

    //runs atleast once for initial generation
    do {
        overlap = false; //reset or set

        // Generate random coordinates within the board bounds
        foodPos.pos->x = rand() % (mainGameMechsRef->getBoardSizeX() - 2) + 1;
        foodPos.pos->y = rand() % (mainGameMechsRef->getBoardSizeY() - 2) + 1;

        // Check for collisions with positions in blockOffList
        for (int i = 0; i < blockOff->getSize(); i++) {
            const objPos& currentBlock = blockOff->getElement(i);
            if (foodPos.pos->x == currentBlock.pos->x && foodPos.pos->y == currentBlock.pos->y) {
                overlap = true;
                break;
            }
        }
    } while (overlap); // Retry until a non-colliding position is found
}

//getter func. for foodPos
objPos Food::getFoodPos() const { return foodPos;}
