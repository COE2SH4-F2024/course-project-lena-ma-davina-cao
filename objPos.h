//define header file
#ifndef OBJPOS_H
#define OBJPOS_H

// Not really a C++ thing
typedef struct 
{
    int x;
    int y;
} Pos;


//class def.
class objPos
{
    public: //public class members
        Pos* pos;        
        char symbol;

        //const. & decons.
        objPos();
        objPos(int xPos, int yPos, char sym);
        // Respect the rule of six / minimum four
        // [TODO] Implement the missing special member functions to meet the minimum four rule
        objPos(const objPos &o);
        ~objPos();
        objPos& operator= (const objPos &o);        

        //methods
        void setObjPos(objPos o);        
        void setObjPos(int xPos, int yPos, char sym);  

        objPos getObjPos() const;
        char getSymbol() const;
        char getSymbolIfPosEqual(const objPos* refPos) const;
        bool isPosEqual(const objPos* refPos) const;
        
};

#endif