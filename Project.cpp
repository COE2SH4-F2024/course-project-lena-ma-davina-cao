#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

// library to use rand() and srand():
#include <stdlib.h>

// include other game header files
#include "GameMechs.h"
#include "Player.h"
#include "Food.h"
#include "objPosArrayList.h"

using namespace std;

//preprocessor const for run-speed
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
    //initialize with a fresh screen
    MacUILib_init();
    MacUILib_clearScreen();

    //allocate memory for ptrs & initalize default object classes
    game = new GameMechs();
    food = new Food(game);
    player = new Player(game, food);

    //get initial player position to generate first food (pre-loop)
    objPosArrayList* playerPos = player->getPlayerPos();
    food->generateFood(playerPos);
}

void GetInput(void)
{
    //typical get input logic
    if(MacUILib_hasChar()){
        game->setInput(MacUILib_getChar());
    }
}

void RunLogic(void)
{
    //update player
    player->updatePlayerDir();
    player->movePlayer();

    //check for exit/ lose/ win condition
    if(game->getInput() == ' ')
        game->setExitTrue();
    if(player->checkSelfCollision()){ //another form of obj. collision
        game->setLoseFlag();
        game->setExitTrue();
    }
    if(game->getScore() == 25){
        game->setWinFlag();
        game->setExitTrue();
    }

    //check for object collision
    if (player->checkFoodConsumption()) {
        // Increment score and generate new food
        game->incrementScore();
        food->generateFood(player->getPlayerPos());
    }

    //clear input after processing (avoid processing same input multiple times)
    game->clearInput();
}

void DrawScreen(void)
{
    //screen reset
    MacUILib_clearScreen();

    // drawing the board
    for (int i = 0; i < game->getBoardSizeY(); i++){
        for (int j = 0; j < game->getBoardSizeX(); j++){ //nested loops to print each line like 2D array
            //check for borders
            if (i == 0 || i == game->getBoardSizeY() - 1 || j == 0 || j == game->getBoardSizeX() - 1){
                MacUILib_printf("#");
            }
            //check if there is food at coordinate
            else if (i == food->getFoodPos().pos->y && j == food->getFoodPos().pos->x){
                MacUILib_printf("*");
            }
            else {  //check any part of snake body is there
                bool printed = false; //bool to check if body has been printed
                
                //loop through size of snake
                for (int k = 0; k < player->getPlayerPos()->getSize(); k++){
                    //check coord. match & process
                    if (i == player->getPlayerPos()->getElement(k).pos->y && j == player->getPlayerPos()->getElement(k).pos->x){
                        MacUILib_printf("%c", player->getPlayerPos()->getElement(k).symbol);
                        printed = true;
                        break;
                    }
                }
                if (!printed){ //if no snake body is printed->whitespace
                    MacUILib_printf(" ");
                }
            }
        }
        MacUILib_printf("\n"); //newline each row
    }

    //print messages for UI
    MacUILib_printf("\nCurrent score is: %d\n", game->getScore());
    MacUILib_printf("Try to get 25 Points!\n");
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
    else if(game->getWinFlagStatus())
        MacUILib_printf("\nImpressive! YOU WIN!!!");
    else if(game->getExitFlagStatus())
        MacUILib_printf("\nQuitter! Better luck next time!");

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

    //call deconstructor for contructors to deallocate memory in constr.
    player->~Player();
    game->~GameMechs();
    food->~Food();

    //uninit. ui
    MacUILib_uninit();
}