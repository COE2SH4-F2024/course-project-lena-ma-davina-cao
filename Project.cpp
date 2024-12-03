#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

// library to use rand() and srand():
#include <stdlib.h>

// include game mech:
#include "GameMechs.h"
#include "Player.h"

#include "Food.h"
#include "objPosArrayList.h"

using namespace std;

#define DELAY_CONST 100000



void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

//global:
Player *player;
GameMechs *game;
Food *food;

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
    food = new Food(game);
    player = new Player(game, food);


    
    //food->generateFood(*player->getPlayerPos());
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
    if(player->checkSelfCollision())
        game->setLoseFlag();
    if (player->checkFoodConsumption()) {
        // Increment score and generate new food
        game->incrementScore();
        food->generateFood(*player->getPlayerPos());
    }
    //clear input after processing
    game->clearInput();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    // drawing the board out of # symbols
    for (int i = 0; i < game->getBoardSizeY(); i++){
        for (int j = 0; j < game->getBoardSizeX(); j++){
            if (i == 0 || i == game->getBoardSizeY() - 1 || j == 0 || j == game->getBoardSizeX() - 1){
                MacUILib_printf("#");
            }
            else if (i == food->getFoodPos().pos->y && j == food->getFoodPos().pos->x){
                MacUILib_printf("*");
            }
            else {  
                bool printed = false;
                
                for (int k = 0; k < player->getPlayerPos()->getSize(); k++){
                    if (i == player->getPlayerPos()->getElement(k).pos->y && j == player->getPlayerPos()->getElement(k).pos->x){
                        MacUILib_printf("%c", player->getPlayerPos()->getElement(k).symbol);
                        printed = true;
                        break;
                    }
                }
                if (!printed){
                    MacUILib_printf(" ");
                }
            }
        }
        MacUILib_printf("\n");
    }
    MacUILib_printf("\nCurrent score is: %d\n", game->getScore());
    MacUILib_printf("Press SPACE to Exit\n");

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{


    //exit/ lose messages
    if (game->getLoseFlagStatus())
        MacUILib_printf("\nOops! You lose!");
    if(game->getExitFlagStatus())
        MacUILib_printf("\nQuitter! Better luck next time!");
    if(game->getWinFlagStatus())
        MacUILib_printf("\nImpressive! YOU WIN!!!");
     
    //deallocate memory on heap
    if (player){
        delete player;
        player = nullptr;
    }
    if (game){
        delete game;
        game = nullptr;
    }
    if (food){
        delete food;
        food = nullptr;
    }
    player->~Player();
    game->~GameMechs();
    food->~Food();

    //uninit. ui
    MacUILib_uninit();
}