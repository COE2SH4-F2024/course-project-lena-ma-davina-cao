#include "Player.h"

Player::Player(GameMechs* thisGMRef, Food* thisFood)
{
    this->mainGameMechsRef = thisGMRef;
    this->myDir = STOP;
    this->playerPosList = new objPosArrayList;
    this->food = thisFood;

    objPos base;
    base.setObjPos(5, 10, '*');

    // more actions to be included
    playerPosList->insertHead(base);
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
    //return if null list
    if (!playerPosList || playerPosList->getSize() == 0) return;

    objPos newPos;
    objPos head = playerPosList->getHeadElement();

    //Movement & wrap-around logic
    switch (myDir){
        case UP:
            newPos.setObjPos(head.pos->x, head.pos->y - 1, '*');
            if (newPos.pos->y < 1) //wrap around logic triggers when at the border(s)
                newPos.setObjPos(head.pos->x, mainGameMechsRef->getBoardSizeY() - 2, '*');
            break;
        case DOWN:
            newPos.setObjPos(head.pos->x, head.pos->y + 1,'*');
            if (newPos.pos->y > mainGameMechsRef->getBoardSizeY() - 2)
                newPos.setObjPos(head.pos->x, 1, '*');     
            break;
        case LEFT:
            newPos.setObjPos(head.pos->x - 1, head.pos->y, '*');
            if (newPos.pos->x < 1)
                newPos.setObjPos(mainGameMechsRef->getBoardSizeX() - 2, playerPosList[0].getHeadElement().pos->y, '*');
            break;
        case RIGHT:
            newPos.setObjPos(head.pos->x + 1, head.pos->y, '*');
            if (newPos.pos->x > mainGameMechsRef->getBoardSizeX() - 2)
                newPos.setObjPos(1, head.pos->y, '*');  
            break;
        default: //triggers when user is in STOP at game start
            return;
            break; //do nothing        
    }
    playerPosList->insertHead(newPos);

    if (!checkFoodConsumption()) {
        playerPosList->removeTail();  // Remove tail unless food is consumed
    } else {
        mainGameMechsRef->incrementScore();
        food->generateFood(playerPosList);
    }
}
/*
void Player::movePlayer()
{
    objPos newPos;
    //Movement & wrap-around logic
    switch (myDir){
        case UP:
            newPos.setObjPos(playerPosList->getHeadElement().pos->x, playerPosList->getHeadElement().pos->y - 1, '*');
            if (newPos.pos->y < 1) //wrap around logic triggers when at the border(s)
                newPos.setObjPos(playerPosList[0].getHeadElement().pos->x, mainGameMechsRef->getBoardSizeY() - 2, '*');
            playerPosList[0].insertHead(newPos);
            if (!checkFoodConsumption()){
                playerPosList[0].removeTail();
            } 
            break;
        case DOWN:
            newPos.setObjPos(playerPosList->getHeadElement().pos->x, playerPosList->getHeadElement().pos->y + 1,'*');
            if (newPos.pos->y > mainGameMechsRef->getBoardSizeY() - 2)
                newPos.setObjPos(playerPosList[0].getHeadElement().pos->x, 1, '*');     
            playerPosList[0].insertHead(newPos);
            if (!checkFoodConsumption()){
                playerPosList[0].removeTail();
            } 
            break;
        case LEFT:
            newPos.setObjPos(playerPosList->getHeadElement().pos->x - 1, playerPosList->getHeadElement().pos->y, '*');
            if (newPos.pos->x < 1)
                newPos.setObjPos(mainGameMechsRef->getBoardSizeX() - 2, playerPosList[0].getHeadElement().pos->y, '*');
            playerPosList[0].insertHead(newPos);
            if (!checkFoodConsumption()){
                playerPosList[0].removeTail();
            } 
            break;
        case RIGHT:
            newPos.setObjPos(playerPosList->getHeadElement().pos->x + 1, playerPosList->getHeadElement().pos->y, '*');
            if (newPos.pos->x > mainGameMechsRef->getBoardSizeX() - 2)
                newPos.setObjPos(1, playerPosList[0].getHeadElement().pos->y, '*');  
            playerPosList[0].insertHead(newPos);
            if (!checkFoodConsumption()){
                playerPosList[0].removeTail();
            }   
            break;
        default: //triggers when user is in STOP at game start
            break; //do nothing
        
    }
}
// More methods to be added
*/
bool Player::checkFoodConsumption()
{
    objPos headPos = playerPosList->getHeadElement();
    objPos foodPos = food->getFoodPos();
    return foodPos.isPosEqual(&headPos);
}


bool Player::checkSelfCollision(){
    //impossible to collide if length less than 3 (or 2 in index)
    if (!playerPosList || playerPosList->getSize() < 2) return false;
    
    
    objPos headPos = playerPosList->getHeadElement();

    for (int i = 1; i < playerPosList->getSize(); i++){
        objPos bodPos = playerPosList->getElement(i);
        if(headPos.isPosEqual(&bodPos)){
            return true;
        }
    }
    return false;
}

/*
bool Player::checkSelfCollision(){
    objPos headPos = playerPosList->getHeadElement();
    objPos bodPos;
    for (int i = 1; i < playerPosList->getSize(); i++){
        bodPos = playerPosList->getElement(i);
        if(headPos.isPosEqual(&bodPos)){
            return true;
        }
    }
    return false;
}
*/