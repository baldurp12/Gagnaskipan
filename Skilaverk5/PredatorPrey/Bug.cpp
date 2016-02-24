#include "Bug.h"


void Bug::move()
{
    while(!moved){
        moveRandomly();
    }
    breedTicks++;
}

void Bug::breed()
{
    if(breedTicks >= BREED_BUGS)
        breedAtAdjacentCell();
}

OrganismType Bug::getType() const{
    return BUG;
}
char Bug::representation() const{
    return charRep;
}

void Bug::generateOffspring(int whereX, int whereY){
    Bug* newBug = new Bug(world, whereX ,whereY);
    breedTicks = 0;
}
