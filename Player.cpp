#include "Player.h"

Player::Player(GameMechs* thisGMRef, Food* thisFood)
{
    this->mainGameMechsRef = thisGMRef;
    this->myDir = STOP;
    this->playerPosList = new objPosArrayList;
    this->food = thisFood;

    objPos base;
    base.setObjPos(5,10, '*');

    this->playerPosList[0].insertHead(base);
}

Player::~Player()
{   
    // delete any heap members here
}

objPosArrayList* Player::getPlayerPos() const
{
    // return the reference to the playerPos array list
    return playerPosList;
    
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic
    char input = mainGameMechsRef->getInput();
    switch(input)
    {                      
        case ' ':  // exit [SPACE]
            mainGameMechsRef->setExitTrue();
            break;
        case 'w': //up
            if (myDir != DOWN) //conditional: can't turn 180 for any of these
                myDir = UP;
            break;
        case 's': //down
            if (myDir != UP)
                myDir = DOWN;
            break;           
        case 'a': //left
            if (myDir != RIGHT)
                myDir = LEFT;
            break;
        case 'd': //right
            if (myDir != LEFT)
                myDir = RIGHT;
            break;   
        default:
            break;
    }
}

void Player::movePlayer()
{
    objPos newPos;
    //Movement & wrap-around logic
    switch (myDir){
        case UP:
            newPos.setObjPos(playerPosList[0].getHeadElement().pos->x, playerPosList[0].getHeadElement().pos->y - 1, '*');
            if (newPos.pos->y < 1) //wrap around logic triggers when at the border(s)
                newPos.setObjPos(playerPosList[0].getHeadElement().pos->x, mainGameMechsRef->getBoardSizeY() - 2, '*');
            playerPosList->insertHead(newPos);
            if (checkFoodConsumption() == true){
                food->generateFood(*playerPosList);
            }
            else if (checkFoodConsumption() == false)
                playerPosList[0].removeTail();
            break;
        case DOWN:
            newPos.setObjPos(playerPosList[0].getHeadElement().pos->x, playerPosList[0].getHeadElement().pos->y + 1,'*');
            if (newPos.pos->y > mainGameMechsRef->getBoardSizeY() - 2)
                newPos.setObjPos(playerPosList[0].getHeadElement().pos->x, 1, '*');     
            playerPosList->insertHead(newPos);
            if (checkFoodConsumption() == true){
                food->generateFood(*playerPosList);
            }
            else if (checkFoodConsumption() == false)
                playerPosList[0].removeTail();
            break;
        case LEFT:
            newPos.setObjPos(playerPosList[0].getHeadElement().pos->x - 1, playerPosList[0].getHeadElement().pos->y, '*');
            if (newPos.pos->x < 1)
                newPos.setObjPos(mainGameMechsRef->getBoardSizeX() - 2, playerPosList[0].getHeadElement().pos->y, '*');
            playerPosList->insertHead(newPos);
            if (checkFoodConsumption() == true){
                food->generateFood(*playerPosList);
            }
            else if (checkFoodConsumption() == false)
                playerPosList[0].removeTail();            
            break;
        case RIGHT:
            newPos.setObjPos(playerPosList[0].getHeadElement().pos->x + 1, playerPosList[0].getHeadElement().pos->y, '*');
            if (newPos.pos->x > mainGameMechsRef->getBoardSizeX() - 2)
                newPos.setObjPos(1, playerPosList[0].getHeadElement().pos->y, '*');     
            playerPosList->insertHead(newPos);
            if (checkFoodConsumption() == true){
                food->generateFood(*playerPosList);
            }
            else if (checkFoodConsumption() == false)
                playerPosList[0].removeTail();            
            break;
        default: //triggers when user is in STOP at game start
            break; //do nothing
        
    }
    
    playerPosList[0].insertHead(newPos);
    if (checkFoodConsumption() != true){
        playerPosList[0].removeTail();
    }
}
// More methods to be added
}

bool Player::checkFoodConsumption()
{
    objPos headPos = playerPosList->getHeadElement();
    objPos foodPos = food->getFoodPos();
    if (foodPos.isPosEqual(&headPos)){
        return true;
    }
    return false;
}
