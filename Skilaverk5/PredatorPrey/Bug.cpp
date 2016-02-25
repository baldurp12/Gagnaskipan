#include "Bug.h"


void Bug::move()
{
    /*if( && world->getAt(x, y-1)->getType() == ANT){
        delete world->getAt(x, y-1);
        world->setAt(x, y, NULL);
        world->setAt(x, y-1, this);
        starveCounter = 0;
        breedTicks++;
    }
    else if(world->getAt(x, y+1)->getType() == ANT){
        delete world->getAt(x, y+1);
        world->setAt(x, y, NULL);
        world->setAt(x, y+1, this);
        starveCounter = 0;
        breedTicks++;
    }
    else if(world->getAt(x-1, y)->getType() == ANT){
        delete world->getAt(x-1, y);
        world->setAt(x, y, NULL);
        world->setAt(x-1, y, this);
        starveCounter = 0;
        breedTicks++;
    }
    else if(world->getAt(x+1, y)->getType() == ANT){
        delete world->getAt(x+1, y);
        world->setAt(x, y, NULL);
        world->setAt(x+1, y, this);
        starveCounter = 0;
        breedTicks++;
    }*/
        while(!moved){
            moveRandomly();
        }
        breedTicks++;
        starveCounter++;
        if(getStarveCounter() >= STARVE_BUGS){
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
    Bug* newBug = new Bug(world, whereX ,whereY);
    newBug = newBug;
    breedTicks = 0;
}

bool Bug::isDead() const{
    return dead;
}

int Bug::getStarveCounter(){
    return starveCounter;
}
