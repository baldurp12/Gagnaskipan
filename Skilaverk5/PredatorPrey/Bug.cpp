#include "Bug.h"



Bug::~Bug(){}

void Bug::move()
{
    Organism* org;
    if((org = world->getAt(x, y+1)) != NULL && org->getType() == ANT){
        delete world->getAt(x, y+1);
        movesTo(x, y+1);
        starveCounter = 0;
        breedTicks++;
    }
    else if((org = world->getAt(x, y-1)) != NULL && org->getType() == ANT){
        delete world->getAt(x, y-1);
        movesTo(x, y-1);
        starveCounter = 0;
        breedTicks++;
    }
    else if((org = world->getAt(x-1, y)) != NULL && org->getType() == ANT){
        delete world->getAt(x-1, y);
        movesTo(x-1, y);
        starveCounter = 0;
        breedTicks++;
    }
    else if((org = world->getAt(x+1, y)) != NULL && org->getType() == ANT){
        delete world->getAt(x+1, y);
        movesTo(x+1, y);
        starveCounter = 0;
        breedTicks++;
    }
    else{
        moveRandomly();
        breedTicks++;
        starveCounter++;
        if(getStarveCounter() >= STARVE_BUGS){
            dead = true;
        }
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
    new Bug(world, whereX ,whereY);
    breedTicks = 0;
}

bool Bug::isDead() const{
    return dead;
}

int Bug::getStarveCounter(){
    return starveCounter;
}
