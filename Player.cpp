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
    switch (input) {
        case 'w': // Move up
            myDir = UP;
            break;
        case 's': // Move down
            myDir = DOWN;
            break;
        case 'a': // Move left
            myDir = LEFT;
            break;
        case 'd': // Move right
            myDir = RIGHT;
            break;
        default:  // If no valid input, stop
            myDir = STOP;
            break;    
    }
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
   /* 
    if (myDir != STOP){   
        if (myDir == UP){
            if (playerPos.y <= 1){  // wraparound --> if it goes out of bounds it wraps back around
                playerPos.y = mainGameMechsRef->boardSizeY - 1;
            }
            playerPos.y--;
        }
        if (myDir == LEFT){
            if (playerPos.x <= 1){
                playerPos.x = 19;
            }
            playerPos.x--;
        }
        if (myDir == DOWN){
            if (playerPos.y >= 8){
                playerPos.y = 0;
            }
            playerPos.y++;
        }
        if (myDir == RIGHT){
            if (playerPos.x >= 18){
                playerPos.x = 0;
            }
            playerPos.x++;
        }
    }
    */
}
// More methods to be added

