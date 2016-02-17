#ifndef ARRAYLIST_H
#define ARRAYLIST_H

template <class T>
class ArrayList
{
    public:
        ArrayList(int size);        // Constructor
        ~ArrayList();               // Destructor
        void append (T const& elem);     // Appends an element at the end of the list
        void next();                // Moves the current position one step right
        void prev();                // Moves the current position one step right
        void moveToStart();         // Set the current position to the start of the list
        void moveToEnd();           // Sets currentPos to last element
        void moveToPos(int const& n);      // Moves current position to the n-th element
        int currPos() const;        // Returns the position of the current element
        int length() const;         // Returns the current length of the list
        T value() const;            // Returns the current element
        void remove();              // Removes current element
        void clear();               // Clears the array
        void insert(T const& elem); // Inserts "elem" at current position


    private:
        int maxSize;        // Maximum size of list
        int currSize;       // Current number of list items
        int currElemPos;    // Position of the current element of the list
        T* arr;             // A pointer to the array holding the list elements
        void doubleArraySize(); // Doubles the size of the Arr array
};

#endif // ARRAYLIST_H
