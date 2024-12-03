//define header file
#ifndef PLAYER_H
#define PLAYER_H

//include necessary header files for use
#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"

//class def.
class Player
{
    public: //public class members
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state

        //const. & decon.
        Player(GameMechs* thisGMRef, Food *thisfood);
        ~Player();

        //member functions (methods)
        objPosArrayList* getPlayerPos() const;        
        void updatePlayerDir();
        void movePlayer();

        // More methods to be added here
        bool checkFoodConsumption();
        bool checkSelfCollision();
        void increasePlayerLength(); //check

    private: //priv. class members
        objPosArrayList* playerPosList;      
        enum Dir myDir;
        GameMechs* mainGameMechsRef; //ref to main game mech.
        Food* food;
};

#endif