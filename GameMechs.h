//define header
#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h> //to seed time in rand

//include other class headers for access
#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;

//class def.
class GameMechs
{
    private: //private class members
        char input;
        bool exitFlag;
        bool loseFlag;
        bool winFlag;
        int score;

        int boardSizeX;
        int boardSizeY;

    public: //pubic class members
        //const. & decon.
        GameMechs();
        GameMechs(int boardX, int boardY);
        ~GameMechs(); // nothing stored on heap so technically unecessary
        
        //methods
        bool getExitFlagStatus() const; 
        void setExitTrue();
        bool getLoseFlagStatus() const;
        void setLoseFlag();

        char getInput() const;
        void setInput(char this_input);
        void clearInput();

        int getBoardSizeX() const;
        int getBoardSizeY() const;
        
        int getScore() const;
        void incrementScore();
        
        // More methods should be added here
        bool getWinFlagStatus()const;
        void setWinFlag();
};

#endif