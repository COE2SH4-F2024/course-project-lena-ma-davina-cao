#include "objPos.h"

//default constructor
objPos::objPos()
{
    pos = new Pos;
    pos->x = 0;
    pos->y = 0;
    symbol = 0; //NULL
}
//spec. constructor
objPos::objPos(int xPos, int yPos, char sym)
{
    pos = new Pos;
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

// Respect the rule of six / minimum four
// [TODO] Implement the missing special member functions to meet the minimum four rule
//copy const. decon.,


//copy const.
objPos::objPos(const objPos &o){
    pos = new Pos;
    pos->x = o.pos->x;
    pos->y = o.pos->y;
    symbol = o.symbol;
}

//deconstructor
objPos::~objPos(){
    delete[] pos;
}

//may need assignment operator function


//setter function (in ref. to another obj)
void objPos::setObjPos(objPos o)
{
    pos->x = o.pos->x;
    pos->y = o.pos->y;
    symbol = o.symbol;
}

//setter function (pos & symb)
void objPos::setObjPos(int xPos, int yPos, char sym)
{
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

//getter function (return obj. with all obj info)
objPos objPos::getObjPos() const
{
    objPos returnPos;
    returnPos.pos->x = pos->x;
    returnPos.pos->y = pos->y;
    returnPos.symbol = symbol;
    
    return returnPos;
}

//get symbol function
char objPos::getSymbol() const
{
    return symbol;
}

//check position match function
bool objPos::isPosEqual(const objPos* refPos) const
{
    return (refPos->pos->x == pos->x && refPos->pos->y == pos->y);
}

//return symbol if pos. match function
char objPos::getSymbolIfPosEqual(const objPos* refPos) const
{
    if(isPosEqual(refPos))
        return symbol;
    else
        return 0;
}
