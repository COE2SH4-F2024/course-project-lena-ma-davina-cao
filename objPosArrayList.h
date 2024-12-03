//define header file
#ifndef OBJPOS_ARRAYLIST_H
#define OBJPOS_ARRAYLIST_H

//preproc. defin. of max (array) size of snake
#define ARRAY_MAX_CAP 200

//include objPos header file for use in objPosArrayList
#include "objPos.h"

//class def.
class objPosArrayList
{
    private: //private class members
        objPos* aList;
        int listSize;
        int arrayCapacity;

    public: //public class members
        //const. & decons.
        objPosArrayList();
        ~objPosArrayList();

        //methods
        int getSize() const;
        void insertHead(objPos thisPos);
        void insertTail(objPos thisPos);
        void removeHead();
        void removeTail();
        
        objPos getHeadElement() const;
        objPos getTailElement() const;
        objPos getElement(int index) const;
};

#endif