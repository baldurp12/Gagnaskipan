#include <iostream>
#include "Organism.h"
#include "World.h"

using namespace std;

// Create an organism at the given coordinates in the given world
Organism::Organism(World* aWorld, int xcoord, int ycoord) {
    world = aWorld;
    x = xcoord;
    y = ycoord;
    breedTicks = 0;
    moved = false;
    world->setAt(x, y, this);
}


void Organism::setMoved(bool hasMoved) {   // flags the organism as moved or not
    moved = hasMoved;
}

bool Organism::hasMoved() const {  // has the organism moved or not?
    return moved;
}

// Makes a random move by calling movesTo().  Called by move() in the subclasses
void Organism::moveRandomly()
{
    /*** You have to implement this function ***/
    /* Implement 2
    */

    int direction = world->randomMove();

    if((direction == UP) && (y < WORLDSIZE -1) && (world->getAt(x, y + 1) == NULL))
    {
        movesTo(x,y + 1);
    }
    else if((direction == DOWN) && (y > 0) && (world->getAt(x, y - 1) == NULL))
    {
         movesTo(x,y - 1);
    }
    else if((direction == LEFT) && (x > 0) && (world->getAt(x - 1, y) == NULL))
    {
         movesTo(x - 1,y);
    }
    else if((direction == RIGHT) && (x < WORLDSIZE -1) && (world->getAt(x + 1, y) == NULL))
    {
         movesTo(x + 1,y);
    }
}

void Organism::movesTo(int xNew, int yNew) // moves the organism from coordinates (x,y) to (xNew,yNew)
{
    /*** You have to implement this function ***/

    world->setAt(xNew, yNew, this); // move organism to the new spot
    world->setAt(x,y,NULL); // change the old spot to empty space
    setMoved(true); // just to make sure we know it has been moved

    // organism new house/home
    x = xNew;
    y = yNew;
}

void Organism::breedAtAdjacentCell()  {
    // breeds an organism at an adjacent cell
	// Tries to produce one new organism in UP, DOWN, LEFT, or RIGHT cell (in that order)
	// Makes sure not to breed off the grid
    // This method calls the generateOffspring() method

    /*** You have to implement this function ***/

    //first check if it is on the map, then check if new spot is empty and then make a babeh if spot is empty
    if((y < WORLDSIZE -1) && (world->getAt(x, y + 1) == NULL))
    {
        generateOffspring(x,y + 1);
    }
    else if((y > 0) && (world->getAt(x, y - 1) == NULL)) // Same as the one above
    {
        generateOffspring(x,y + 1);
    }
    else if((x > 0) && (world->getAt(x - 1, y) == NULL)) // Still the same
    {
        generateOffspring(x - 1,y);
    }
    else if((x < WORLDSIZE -1) && (world->getAt(x + 1,y) == NULL)) // anything different?? answer nope still the same
    {
        generateOffspring(x + 1,y);
    }

}

bool Organism::isDead() const { // Returns true if organism is dead, false otherwise.
    cout << "This should not happen" << endl;
    return false;
}
