#ifndef BUG_H
#define BUG_H
#include "World.h"


class Bug : public Organism
{

    public:
        Bug();
    Bug(World* world, int xcoord, int ycoord):Organism( world, xcoord, ycoord) { starveCounter = 0;}
        virtual void move();
        void breed();
        virtual OrganismType getType() const;
        virtual char representation() const;
        virtual void generateOffspring(int whereX, int whereY);
        int resetStarveCounter();
        int getStarveCounter();
    private:
        int starveCounter;
        char charRep = 'X';


};

#endif // BUG_H
