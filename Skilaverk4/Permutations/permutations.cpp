// ***************************************************************
// This is the implementation file for the Permutation class
// ***************************************************************
#include "permutations.h"

// Default constructor
Permutations::Permutations() : myPerms(NULL) {
}

// Destructor
Permutations::~Permutations() {
    removeAll();
}

// Generates permutations for set of size n
void Permutations::generate(int n) {
    if (myPerms != NULL) { // First clean the permutations if necessary
        removeAll();
    }

    int* aSet = new int[n];
    // Populate the set with the first n whole numbers
    for (int i = 0; i < n; i++) {
        aSet[i] = i+1;
    }

    // Use the recursive permutations function to generate all the permutations
    myPerms = permutate(aSet, n);
    // Deallocate aSet
    delete [] aSet;
}

// Prints all the permutations
void Permutations::print() const
{
    unsigned int x = 1;
    for(NodePtr iter = myPerms; iter!= NULL; iter = iter->next, x++)
    {
        cout << x << ": ";
        printSet( iter->setPtr, iter->setSize);
        cout << endl;
    }
    cout << endl;
}

// Private functions start here
void Permutations::printSet(int set[], int size) const {
    cout << "{";
    for (int i = 0; i < size; i++) {
        if (i > 0) {
            cout << ",";
        }
        cout << set[i];
    }
    cout << "}";
}

void Permutations::remove(NodePtr node)
{
    delete [] node->setPtr;  // delete the set inside the node
    delete node;             // delete the node
}

// Remove every node from the list
void Permutations::removeAll()
{
    while (myPerms != NULL) {
        NodePtr next = myPerms->next;
        remove(myPerms);              // delete this node
        myPerms = next;
    }
}

void Permutations::insert(int num, NodePtr smaller, NodePtr& larger)
{
    /*int multiple = 1;
    for(int factorial = 1; factorial <= num; factorial++){
        multiple *= factorial;
    }

    larger = new Node;
    larger->setPtr = new int[num];


    NodePtr tempB = NULL;
    larger->next = new Node;
    NodePtr tempA = larger->next;
    tempA->setPtr = new int[num];

    for(int j = 1; j < multiple; j++){
        tempB = new Node;
        tempB->setPtr = new int[num];
        tempA->next = tempB;
        tempA = tempB;
    }*/

// For each permutation of the smaller list, make a permutation (pointed to by 'larger')
// that includes the number 'num' in each position

// You have to implement this function, but it is partly given below.

    while (smaller != NULL) { // Traverse the 'smaller' list
        for (int i = 0; i <= smaller->setSize; i++) { // Iterate through the set.
            NodePtr largeNode = new Node;
            if(large == NULL){
                large = largeNode;
            }
            for(int j = 0; j<num; j++){

            }


            // Create a new set which is one larger than the current set and add 'num' in the correct pos
            // This will become part of the list pointed to by 'larger'

        }
        // Delete the node we just used, and move to the next one
        NodePtr next = smaller->next;
        remove(smaller);
        smaller = next;
    }

}

// Recursive function that returns a list containing all of the permutations of the set
NodePtr Permutations::permutate(int set[], int size)
{
    if(size == 1)
    {
        NodePtr newNode = new Node;
        newNode->next = NULL;
        newNode->setPtr = new int[1];
        newNode->setSize = 1;
        newNode->setPtr[0] = set[0];
        return newNode;
    }

    NodePtr larger = NULL;
    insert( set[size], permutate(set, size -1), larger);
    return larger;
}
