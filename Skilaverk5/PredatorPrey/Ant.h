#ifndef ANT_H
#define ANT_H
#include "World.h"


using namespace std;

class Ant : public Organism
{
    public:
    Ant();
    Ant(World* world, int xcoord, int ycoord):Organism( world, xcoord, ycoord) { }
    virtual ~Ant();
        virtual void move();
        virtual void breed();
        virtual OrganismType getType() const;
        virtual char representation() const;
        virtual void generateOffspring(int whereX, int whereY);
        virtual bool isDead() const;
    private:
        bool dead;
        char charRep = 'o';

};

#endif // ANT_H
