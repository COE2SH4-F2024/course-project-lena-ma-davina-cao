#include "objPosArrayList.h"

// Paste your Tested implementation here.
// Paste your Tested implementation here.
// Paste your Tested implementation here.
objPosArrayList::objPosArrayList()
{
    listSize = 0;
    arrayCapacity = 200; //dcheck
    aList = new objPos[arrayCapacity];
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
    ++listSize;

    for (int i = listSize - 1; i >= 0; i--){
        if (i > 0){
            aList[i].pos->x = aList[i-1].pos->x;
            aList[i].pos->y = aList[i-1].pos->y;
            aList[i].symbol = aList[i-1].symbol;
        }
        else if (i == 0){
            aList[i].pos->x = thisPos.pos->x;
            aList[i].pos->y = thisPos.pos->y;
            aList[i].symbol = thisPos.symbol;
        }
    }
}


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
        --listSize;
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
        --listSize;
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