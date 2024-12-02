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

    
    player = new objPos();
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
<<<<<<< HEAD

    // drawing the board out of # symbols
    int i, j, k;
    for (i = 0; i <= game->getBoardSizeY(); i++){
        for (j = 0; j <= game->getBoardSizeX(); j++){
            if (i == 0 || i == game->getBoardSizeY() || j == 0 || j == game->getBoardSizeX()){
                MacUILib_printf("#");
            }
            else if (i == player->pos->y && j == player->pos->x){    //dynamic portion; print symbol at player position
                MacUILib_printf("%c", player->symbol);
            }
            else{
                    MacUILib_printf(" ");   
                }

            }
        }
    MacUILib_printf("\n");


=======
>>>>>>> e47af48cdd950c2711c6c3e63d9f0a2112930a66
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
