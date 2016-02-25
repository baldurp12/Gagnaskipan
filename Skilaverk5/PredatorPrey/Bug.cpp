#include "Bug.h"


void Bug::move()
{
    Organism* org;
    if((y < WORLDSIZE) && ((org = world->getAt(x, y+1)) != NULL) && (org->getType() == ANT)){
        delete world->getAt(x, y+1);
        movesTo(x,x+1);
        starveCounter = 0;
    }
    else if((y > 0) && ((org = world->getAt(x, y-1)) != NULL) && (org->getType() == ANT)){
        delete world->getAt(x, y-1);
        movesTo(x,y-1);
        starveCounter = 0;
    }
    else if((x > 0) && ((org = world->getAt(x-1, y)) != NULL) && (org->getType() == ANT)){
        delete world->getAt(x-1, y);
        world->setAt(x,y,NULL);
        starveCounter = 0;
    }
    else if((x < WORLDSIZE) && ((org = world->getAt(x+1, y)) != NULL) && (org->getType() == ANT)){
        delete world->getAt(x+1, y);
        movesTo(x+1,y);
        starveCounter = 0;
    }
    else{
        while(!moved){
            moveRandomly();
        }
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
