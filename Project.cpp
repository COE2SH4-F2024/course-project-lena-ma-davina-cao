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

    exitFlag = false;
    
    game = new GameMechs();

}

void GetInput(void)
{
    
}

void RunLogic(void)
{
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();

    // drawing the board out of # symbols
    for (int r = 0; r < 20; r++){
        for (int c = 0; c < 10; c++){
            if (r == 0 || r == 9 || c == 0 || c == 19){
                board.setObjPos(c, r, '#');
            }
        }
    }



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
