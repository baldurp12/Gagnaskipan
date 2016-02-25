#include <iostream>
#include <ctime>    // for time
#include "World.h"
using namespace std;

int main()
{
    World myWorld(1234);

    myWorld.display();

    char ch;
    cin.get(ch);

    while (ch != 'q') {
        myWorld.simulateOneStep();
        myWorld.display();
        cin.get(ch);
    }

    return 0;
}
