#ifndef FOOD_H
#define FOOD_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"

using namespace std;

class Food
{
    private:
        objPos foodPos;
        GameMechs* mainGameMechsRef;

    public:
        Food(GameMechs* thisGMRef);
        ~Food();
        void generateFood(objPos blockOff);
        objPos getFoodPos() const;

};


#endif