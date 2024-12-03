//include class header
#include "objPosArrayList.h"

//default constructor
objPosArrayList::objPosArrayList()
{
    listSize = 0;
    arrayCapacity = 200;
    aList = new objPos[arrayCapacity];
}

//destructor
objPosArrayList::~objPosArrayList()
{
    //delete
    delete[] aList;
}

//getter function for size
int objPosArrayList::getSize() const
{
    return listSize;
}

//insert new element into beginning of array
void objPosArrayList::insertHead(objPos thisPos)
{
    listSize++;

    //loop through array obj. backwards
    for (int i = listSize; i >= 0; --i){
        if (i > 0){
            aList[i].pos->x = aList[i-1].pos->x;
            aList[i].pos->y = aList[i-1].pos->y;
            aList[i].symbol = aList[i-1].symbol;
        }
        else if (i == 0){ //
            aList[i].pos->x = thisPos.pos->x;
            aList[i].pos->y = thisPos.pos->y;
            aList[i].symbol = thisPos.symbol;                
        }
    }
}

//insert element at end of obj. array
void objPosArrayList::insertTail(objPos thisPos)
{
    
    ++listSize;

    aList[listSize - 1].pos->x = thisPos.pos->x;
    aList[listSize - 1].pos->y = thisPos.pos->y;
    aList[listSize - 1].symbol = thisPos.symbol;
}

void objPosArrayList::removeHead()
{
    if (listSize > 0){
        listSize--;
    }
    for (int i = 0; i < listSize - 1; i++){
        aList[i].pos->x = aList[i+1].pos->x;
        aList[i].pos->y = aList[i+1].pos->y;
        aList[i].symbol = aList[i+1].symbol;
    }
}

void objPosArrayList::removeTail()
{
    if (listSize != 0){
        listSize--;
    }
}

objPos objPosArrayList::getHeadElement() const
{
    return objPos(aList[0]);
}

objPos objPosArrayList::getTailElement() const
{
    return objPos(aList[listSize - 1]);
}

objPos objPosArrayList::getElement(int index) const
{
    return objPos(aList[index]);
}