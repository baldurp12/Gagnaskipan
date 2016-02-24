#ifndef ANT_H
#define ANT_H
#include "Organism.h"


class Ant : public Organism
{

    public:
        Ant (World* aWorld, int xCoord, int yCoord);
        void move();
        void breed();
        virtual OrganismType getType();
        virtual char representation();
        virtual void generateOffspring(int whereX, int whereY);
    private:
        char charRep = 'A';

};

#endif // ANT_H
