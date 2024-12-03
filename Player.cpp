//include header file for Player class
#include "Player.h"


//constructor
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


//deconstructor
Player::~Player()
{   
    delete playerPosList;
    // delete any heap members here
}


//return objpos array ptr
objPosArrayList* Player::getPlayerPos() const
{
    // return the reference to the playerPos array list
    return playerPosList;
    
}


//update player direction function
void Player::updatePlayerDir()
{
    // PPA3 input processing logic altered for project
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
            break; //triggers at beginning during STOP
    }
}


//player movement function
void Player::movePlayer()
{   
    //return if null list
    if (!playerPosList || playerPosList->getSize() == 0) return;

    //save new position in new objPos
    objPos newPos;
    //save head of snake (array) into new obj for ease of access
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
    
    //insert new position at beginning of array
    playerPosList->insertHead(newPos);

    // Remove tail unless food is consumed
    if (!checkFoodConsumption()) {
        playerPosList->removeTail();
    } else { //increment score and regen. food on obj. collision
        mainGameMechsRef->incrementScore();
        food->generateFood(playerPosList);
    }
}


//food collision check function
bool Player::checkFoodConsumption()
{
    //save head & food position into new objPos objects
    objPos headPos = playerPosList->getHeadElement();
    objPos foodPos = food->getFoodPos();

    //compare positions with objPos class function call
    return foodPos.isPosEqual(&headPos);
}


//check self collision function
bool Player::checkSelfCollision(){
    //impossible to collide if length less than 5 (or 4 in index)
    if (!playerPosList || playerPosList->getSize() < 4) return false;
    
    //save head position in new object
    objPos headPos = playerPosList->getHeadElement();

    //loop through array
    for (int i = 1; i < playerPosList->getSize(); i++){
        //check if head position is equal to body anywhere
        objPos bodPos = playerPosList->getElement(i);
        if(headPos.isPosEqual(&bodPos)){ 
            return true;
        }
    }

    return false; //return false otherwise
}