#include "Player.h"

Player::Player(GameMechs* thisGMRef)
{
    this->mainGameMechsRef = thisGMRef;
    this->myDir = STOP;
    this->playerPosList = new objPosArrayList;

    objPos base;
    base.setObjPos(5,10, '*');

    // more actions to be included
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
    //Movement & wrap-around logic
    switch (myDir){
        case UP:
            playerPosList[0].getHeadElement().pos->y--;
            if (playerPosList[0].getHeadElement().pos->y < 1) //wrap around logic triggers when at the border(s)
                playerPosList[0].getHeadElement().pos->y = mainGameMechsRef->getBoardSizeY() - 2;
            break;
        case DOWN:
            playerPosList[0].getHeadElement().pos->y++;
            if (playerPosList[0].getHeadElement().pos->y > mainGameMechsRef->getBoardSizeY() - 2)
                playerPosList[0].getHeadElement().pos->y = 1;
            break;
        case LEFT:
            playerPosList[0].getHeadElement().pos->x--;
            if (playerPosList[0].getHeadElement().pos->x < 1)
                playerPosList[0].getHeadElement().pos->x = mainGameMechsRef->getBoardSizeX() - 2;
            break;
        case RIGHT:
            playerPosList[0].getHeadElement().pos->x++;
            if (playerPosList[0].getHeadElement().pos->x > mainGameMechsRef->getBoardSizeX() - 2)
                playerPosList[0].getHeadElement().pos->x = 1;
            break;
        default: //triggers when user is in STOP at game start
            break; //do nothing
    }
}
// More methods to be added

