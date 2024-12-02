#include "GameMechs.h"

GameMechs::GameMechs()
{
    this-> input;
    this-> exitFlag = 0;
    this-> loseFlag = 0;
    this-> winFlag = 0;
    this-> score = 0;

    this-> boardSizeX = 30;
    this-> boardSizeY = 15;

    this-> food = objPos();
}

GameMechs::GameMechs(int boardX, int boardY)
{
    this-> input;
    this-> exitFlag = 0;
    this-> loseFlag = 0;
    this-> winFlag = 0;
    this-> score = 0;

    this-> boardSizeX = boardX;
    this-> boardSizeY = boardY;

    this->food = objPos();
}

// do you need a destructor?
GameMechs::~GameMechs()
{
    //nothing on heap yet
}

bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}
    

char GameMechs::getInput() const
{
    return input;
}

int GameMechs::getScore() const
{
    return score;
}

void GameMechs::incrementScore()
{
    score++;
}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = '0'; //null
}

// More methods should be added here
bool GameMechs::getWinFlagStatus() const {
    return winFlag;
}

void GameMechs::setWinFlag(){
    winFlag = true;
}