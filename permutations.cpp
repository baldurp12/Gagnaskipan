// ***************************************************************
// This is the implementation file for the Permutation class
// ***************************************************************
#include "permutations.h"

// Default constructor
Permutations::Permutations() : myPerms(NULL)
{
}

// Destructor
Permutations::~Permutations()
{
    removeAll();
}

// Generates permutations for set of size n
void Permutations::generate(int n)
{
    if (myPerms != NULL)   // First clean the permutations if necessary
    {
        removeAll();
    }

    int* aSet = new int[n];
    // Populate the set with the first n whole numbers
    for (int i = 0; i < n; i++)
    {
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
    // You have to implement this function.
    // It should call the printSet function
    int counter = 1;
    for(NodePtr p = myPerms; p != NULL; p=p->next)
    {
        cout <<  counter << ": " ;
        printSet(p->setPtr, p->setSize);

        cout << endl;
        counter++;
    }
}

// Private functions start here
void Permutations::printSet(int set[], int size) const
{
    cout << "{";
    for (int i = 0; i < size; i++)
    {
        if (i > 0)
        {
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
    while (myPerms != NULL)
    {
        NodePtr next = myPerms->next;
        remove(myPerms);              // delete this node
        myPerms = next;
    }
}

void Permutations::insert(int num, NodePtr smaller, NodePtr& larger)
{
    while (smaller != NULL)   // Traverse the 'smaller' list
    {

        for (int i = 0; i <= smaller->setSize; i++)   // Iterate through the set.
        {
            int* newSet  = new int[num];  //new array that is of a size num
            NodePtr newNode = new Node;  // pointer to the new node
            newNode->setPtr = newSet; // newNode points on the new array (still empty)
            newNode->next = larger; //newNode points t the same what larger point wich is NULL like mu back account
            newNode->setSize = num; //obvious
            larger = newNode; //now larger is pointing to newNode

            //now I want to copy what is in smaller array
            for(int j = 0; j < i; j++)
            {
                newSet[j] = smaller->setPtr[j]; //copy until you hit i
            }
            newSet[i] = num; //who knows
            for(int k = i +1; k <= smaller->setSize; k++) //já einmitt þetta virkar,
            {
                newSet[k] = smaller->setPtr[k - 1]; // after you hit i you want to move by one to the right but not out of bounds of array and copy whats left
            }
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
    // You have to implement this function.
    // It should call itself recursively and also call the insert function
    if(size == 1) //base case if there is only one integer in the array
    {
        NodePtr myList = new Node; //create new node
        myList->next = NULL;
        myList->setPtr = new int[1]; //let  the new node to point to an array of size 1
        myList->setPtr[0] =  set[0]; // put in to the new array the value that is in set at the index 0 ---coz it is array :)
        myList->setSize = size;
        return myList; //returns the one and only combination of one integer
    }
    else //but what if there are more than one integer in array?
    {
        NodePtr larger = NULL; //get new pointer that is NULL like my future
        int* newSet = new int[size - 1];  //create new array that  is of size 1 less then original size, that is how we cuts off the last integer in array
        for(int i = 0; i <  size - 1; i++) //keyrum þetta í gang
        {
            newSet[i] = set[i]; //copy what is in the array (minus the last one)
        }
        NodePtr smaller = permutate(newSet, size-1); //permutate returns new list that is now smaller
        insert(size, smaller, larger); //inserting the num into the smaller list, larger is past by reference so we get larger list out of it
        delete [] newSet; //we are done with this, we dont need that we throw it away
        return larger; //and we return the new pretty list
    }

}
