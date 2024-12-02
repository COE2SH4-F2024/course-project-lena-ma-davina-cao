#include "Player.h"

Player::Player(GameMechs* thisGMRef)
{
    this->mainGameMechsRef = thisGMRef;
    this->myDir = STOP;

    // more actions to be included
    this->playerPos.pos->x = 10;
    this->playerPos.pos->y = 5;
    this->playerPos.symbol = '*';
}

Player::~Player()
{   
    // delete any heap members here
}

objPos Player::getPlayerPos() const
{
    // return the reference to the playerPos array list
    return playerPos;
    
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
            playerPos.pos->y--;
            if (playerPos.pos->y < 1) //wrap around logic triggers when at the border(s)
                playerPos.pos->y = mainGameMechsRef->getBoardSizeY() - 2;
            break;
        case DOWN:
            playerPos.pos->y++;
            if (playerPos.pos->y > mainGameMechsRef->getBoardSizeY() - 2)
                playerPos.pos->y = 1;
            break;
        case LEFT:
            playerPos.pos->x--;
            if (playerPos.pos->x < 1)
                playerPos.pos->x = mainGameMechsRef->getBoardSizeX() - 2;
            break;
        case RIGHT:
            playerPos.pos->x++;
            if (playerPos.pos->x > mainGameMechsRef->getBoardSizeX() - 2)
                playerPos.pos->x = 1;
            break;
        default: //triggers when user is in STOP at game start
            break; //do nothing
    }
}
// More methods to be added

