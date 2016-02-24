#ifndef ANT_H
#define ANT_H
#include "World.h"


using namespace std;

class Ant : public Organism
{
    public:
    Ant();
    Ant(World* world, int xcoord, int ycoord):Organism( world, xcoord, ycoord) { }
        virtual void move();
        void breed();
        virtual OrganismType getType() const;
        virtual char representation() const;
        void generateOffspring(int whereX, int whereY);
    private:
        char charRep = 'o';

};

#endif // ANT_H
