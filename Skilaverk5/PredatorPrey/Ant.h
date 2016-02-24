#ifndef ANT_H
#define ANT_H
#include "World.h"


class Ant : public Organism
{
    public:
        Ant (int xcoord, int ycoord):Organism( aWorld, xcoord, ycoord);
        void move();
        void breed();
        virtual OrganismType getType() const;
        virtual char representation() const;
        void generateOffspring(int whereX, int whereY);
    private:
        char charRep = 'A';

};

#endif // ANT_H
