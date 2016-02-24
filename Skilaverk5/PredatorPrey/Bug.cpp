#include "Bug.h"


void Bug::move()
{
    while(!moved){
        moveRandomly();
    }
}

void Bug::breed()
{

}

OrganismType Bug::getType() const{
    return BUG;
}
char Bug::representation() const{
    return charRep;
}

void Bug::generateOffspring(int whereX, int whereY){
}
