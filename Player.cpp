#include "Player.h"

Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.pos->x = 10;
    playerPos.pos->y = 5;
    playerPos.symbol = '*';
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
    if(input != '0')  // if not null character
    {
        switch(input)
        {                      
            case ' ':  // exit [ESC]
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
        input = '0'; //reset to 0 so no continuous process of same char
    }
}

void Player::movePlayer()
{
    // player move + wrap
    if (myDir != STOP){   
        if (myDir == UP){
            if (playerPos.pos->y <= 1){  // wraparound --> if it goes out of bounds it wraps back around
                playerPos.pos->y = mainGameMechsRef->getBoardSizeX() - 2;
            }
            playerPos.pos->y--;
        }
        if (myDir == LEFT){
            if (playerPos.pos->x <= 1){
                playerPos.pos->x = mainGameMechsRef->getBoardSizeX() - 2;
            }
            playerPos.pos->x--;
        }
        if (myDir == DOWN){
            if (playerPos.pos->y >= mainGameMechsRef->getBoardSizeX() - 2){
                playerPos.pos->y = 0;
            }
            playerPos.pos->y++;
        }
        if (myDir == RIGHT){
            if (playerPos.pos->x >= mainGameMechsRef->getBoardSizeX() - 2){
                playerPos.pos->x = 0;
            }
            playerPos.pos->x++;
        }
    }
}
// More methods to be added

