#include "Ant.h"

void Ant::move()
{
    while(!moved)
    {
       moveRandomly();
    }
}

void Ant::breed()
{

}

OrganismType Ant::getType() const{
    return ANT;
}
char Ant::representation() const{
    return charRep;
}

void Ant::generateOffspring(int whereX, int whereY){
}
