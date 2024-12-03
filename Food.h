//define header file
#ifndef FOOD_H
#define FOOD_H

//include time for random # gen.
#include <time.h>

//include other header files for use
#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"

using namespace std;

//class def.
class Food
{
    private: //private class members
        objPos foodPos;
        GameMechs* mainGameMechsRef;

    public: //public class members
        //const. & decon.
        Food(GameMechs* thisGMRef);
        ~Food();

        //methods
        void generateFood(objPosArrayList* blockOff);
        objPos getFoodPos() const;

};


#endif 