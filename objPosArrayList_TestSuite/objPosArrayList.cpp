#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    objPos* aList;
    listSize = 1;
    arrayCapacity = 1; //dcheck
}

objPosArrayList::~objPosArrayList()
{
    //delete
    for (int i = 0; i < listSize; i++){
        delete[] &aList[i];
    }

    delete[] aList;
}

int objPosArrayList::getSize() const
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    listSize++;

    for (int i = 0; i < listSize; i++){
        objPos temp(aList[i+1]);
        if(i == 0){
            aList[i].pos->x = thisPos.pos->x;
            aList[i].pos->y = thisPos.pos->y;
            aList[i].symbol = thisPos.symbol;
        }
        else {
            aList[i].pos->x = temp.pos->x;
            aList[i].pos->y = temp.pos->y;
            aList[i].symbol = temp.symbol;
        }
    }
}

void objPosArrayList::insertTail(objPos thisPos)
{
    
}

void objPosArrayList::removeHead()
{
    
}

void objPosArrayList::removeTail()
{
    
}

objPos objPosArrayList::getHeadElement() const
{
    
}

objPos objPosArrayList::getTailElement() const
{
    
}

objPos objPosArrayList::getElement(int index) const
{
    
}