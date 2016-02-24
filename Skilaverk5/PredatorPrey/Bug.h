#ifndef BUG_H
#define BUG_H
#include "Organism.h"


class Bug : public Organism
{

    public:
        Bug (World* aWorld, int xCoord, int yCoord);
        void move();
        void breed();
        virtual OrganismType getType() const;
        virtual char representation() const;
        virtual void generateOffspring(int whereX, int whereY);
        int resetStarveCounter();
        int getStarveCounter();
    private:
        int starveCounter;

};

#endif // BUG_H
