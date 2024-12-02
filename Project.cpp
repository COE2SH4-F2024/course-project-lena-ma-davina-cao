#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

// library to use rand() and srand():
#include <stdlib.h>

// include game mech:
#include "GameMechs.h"
#include "Player.h"

using namespace std;

#define DELAY_CONST 100000

//exitflag previously here as global bool

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

//global:
Player *player;
GameMechs *game;

int main(void)
{

    Initialize();

    while(!game->getExitFlagStatus())  
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
    player = new Player(game);
}

void GetInput(void)
{
    if(MacUILib_hasChar()){
        game->setInput(MacUILib_getChar());
    }
}

void RunLogic(void)
{
    player->updatePlayerDir();
    player->movePlayer();

    if(game->getInput() == ' ')
        game->setExitTrue();

    //clear input after processing
    game->clearInput();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    MacUILib_printf("%c", game->getBoardSizeX());
    // drawing the board out of # symbols
    for (int i = 0; i <= game->getBoardSizeY(); i++){
        for (int j = 0; j <= game->getBoardSizeX(); j++){
            if (i == 0 || i == game->getBoardSizeY() - 1 || j == 0 || j == game->getBoardSizeX() - 1){
                MacUILib_printf("#");
            }
            else if (i == player->getPlayerPos().pos->y && j == player->getPlayerPos().pos->x){  //dynamic portion; print symbol at player position
                MacUILib_printf("%c", player->getPlayerPos().getSymbol());
            }
            else{
                MacUILib_printf(" ");   
            }
        }
        MacUILib_printf("\n");
    }

    MacUILib_printf("\nCurrent score is: %d\n", game->getScore());
    MacUILib_printf("Press SPACE to Exit\n");
    MacUILib_printf("Current score is: %d\n", game->getScore());


}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();

    //exit/ lose messages
    if (game->getLoseFlagStatus())
        MacUILib_printf("Oops! You lose!");
    if(game->getExitFlagStatus())
        MacUILib_printf("Quitter! Better luck next time!");
    if(game->getWinFlagStatus())
        MacUILib_printf("Impressive! YOU WIN!!!");
     
    //deallocate memory on heap
    if (player){
        delete player;
        player = nullptr;
    }
    if (game){
        delete game;
        game = nullptr;
    }

    //uninit. ui
    MacUILib_uninit();
}
