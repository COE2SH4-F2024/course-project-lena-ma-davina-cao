//include objPos header file
#include "objPos.h"

//default constructor
objPos::objPos()
{
    //def. & init. deafault values
    this->pos = new Pos;
    this->pos->x = 0;
    this->pos->y = 0;
    this->symbol = 0; //NULL
}

//spec. constructor
objPos::objPos(int xPos, int yPos, char sym)
{
    //def. & init. using passed values
    this->pos = new Pos;
    this->pos->x = xPos;
    this->pos->y = yPos;
    this->symbol = sym;
}


//copy const.
objPos::objPos(const objPos &o){
    //copy values from pre-ex. passed obj.
    this->pos = new Pos;
    this->pos->x = o.pos->x;
    this->pos->y = o.pos->y;
    this->symbol = o.symbol;
}


//deconstructor
objPos::~objPos(){ delete pos;}

//copy assignment op.
objPos& objPos::operator= (const objPos &o)
{
    if (this != nullptr)
    {
        this->pos = new Pos;
        this->pos->x = o.pos->x;
        this->pos->y = o.pos->y;
        this->symbol = o.symbol;
    }
    return *this;
}


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
char objPos::getSymbol() const { return symbol; }


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