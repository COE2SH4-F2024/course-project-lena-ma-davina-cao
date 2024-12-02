#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

// library to use rand() and srand():
#include <stdlib.h>

// include game mech:
#include "GameMechs.h"

using namespace std;

#define DELAY_CONST 100000

bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

//global:
objPos board;
objPos itemBin;
objPos *player;

GameMechs *game;

int main(void)
{

    Initialize();

    while(exitFlag == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    
    game = new GameMechs();

}

void GetInput(void)
{
    if (MacUILib_getChar){
        game->setInput(MacUILib_getChar());
    }
}

void RunLogic(void)
{

}

void DrawScreen(void)
{
    MacUILib_clearScreen();
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    if (game){
        delete game;
        game = nullptr;
    }

    MacUILib_uninit();
}
