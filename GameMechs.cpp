//include GameMechs header file
#include "GameMechs.h"

//default constructor
GameMechs::GameMechs()
{
    //def. & init. with default values
    this-> input = '\0';
    this-> exitFlag = 0;
    this-> loseFlag = 0;
    this-> winFlag = 0;
    this-> score = 0;

    this-> boardSizeX = 30;
    this-> boardSizeY = 15;
}

//spec. constructor
GameMechs::GameMechs(int boardX, int boardY)
{
    //def. & init. with default & passed values
    this-> input;
    this-> exitFlag = 0;
    this-> loseFlag = 0;
    this-> winFlag = 0;
    this-> score = 0;

    this-> boardSizeX = boardX;
    this-> boardSizeY = boardY;
}

// do you need a destructor? //no!
GameMechs::~GameMechs() {  } //nothing on heap yet


//GETTER FUNCTIONS (returns the value requested)
bool GameMechs::getExitFlagStatus() const {return exitFlag;}
bool GameMechs::getLoseFlagStatus() const {return loseFlag;}  
char GameMechs::getInput() const {return input;}
int GameMechs::getScore() const {return score;}
int GameMechs::getBoardSizeX() const {return boardSizeX;}
int GameMechs::getBoardSizeY() const { return boardSizeY;}
bool GameMechs::getWinFlagStatus() const { return winFlag;}



//SETTER/ MODIFYER FUNCTIONS (alters a value stored in the class)
void GameMechs::incrementScore(){score++;}
void GameMechs::setExitTrue(){ exitFlag = true;}
void GameMechs::setLoseFlag(){ loseFlag = true;}
void GameMechs::setInput(char this_input){ input = this_input;}
void GameMechs::clearInput(){ input = '0'; } //null
void GameMechs::setWinFlag(){ winFlag = true; }