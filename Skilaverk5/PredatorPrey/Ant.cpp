#include <iostream>
#include "Ant.h"

using namespace std;

Ant::~Ant(){}

void Ant::move()
{

        moveRandomly();
    breedTicks++;
}

void Ant::breed()
{
    if(breedTicks >= BREED_ANTS)
    {
        breedAtAdjacentCell();
    }
}

bool Ant::isDead() const{
    return dead;
}

OrganismType Ant::getType() const{
    return ANT;
}
char Ant::representation() const{
    return charRep;
}

void Ant::generateOffspring(int whereX, int whereY){
    new Ant(world, whereX ,whereY);
    breedTicks = 0;
}
