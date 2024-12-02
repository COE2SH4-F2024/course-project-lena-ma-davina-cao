#include "GameMechs.h"

GameMechs::GameMechs()
{
    char input;
    bool exitFlag = 0;
    bool loseFlag = 0;
    int score = 0;

    int boardSizeX = 30;
    int boardSizeY = 15;

    objPos food;
}

GameMechs::GameMechs(int boardX, int boardY)
{
    char input;
    bool exitFlag = 0;
    bool loseFlag = 0;
    int score = 0;

    int boardSizeX = boardX;
    int boardSizeY = boardY;

    objPos food;
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