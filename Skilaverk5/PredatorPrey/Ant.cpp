#include <iostream>
#include "Ant.h"

using namespace std;
void Ant::move()
{
    moveRandomly();
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
