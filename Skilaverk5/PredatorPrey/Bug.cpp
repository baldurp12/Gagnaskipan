#include "Bug.h"


void Bug::move()
{
    while(!moved){
        moveRandomly();
    }
    breedTicks++;
    starveCounter++;
    if(getStarveCounter() >= STARVE_BUGS){
            cout << "bug died" << endl;
        dead = true;
    }
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
    cout << "trying to breed a bug at X: " << whereX << "  " << "Y: " << whereY << endl;
    Bug* newBug = new Bug(world, whereX ,whereY);
    newBug = newBug;
    breedTicks = 0;
}

bool Bug::isDead(){
    return dead;
}

int Bug::getStarveCounter(){
    return starveCounter;
}
