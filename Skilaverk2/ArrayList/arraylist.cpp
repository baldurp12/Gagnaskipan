#include "arraylist.h"
#include <assert.h>
#include <iostream>

using namespace std;

template <class T>
ArrayList<T>::ArrayList(int size)
{
    maxSize = size;
    currSize = 0;
    moveToStart();
    arr = new T[maxSize];
}

template <class T>
ArrayList<T>::~ArrayList()
{
    delete [] arr;
}

template <class T>
void ArrayList<T>::append(T const& elem) {
    //assert(currSize < maxSize); // List capacity exceeded
    if(currSize >= maxSize){
        doubleArraySize();
    }
        arr[currSize] = elem;
        currSize++;
}

template <class T>
void ArrayList<T>::next() {
    if (currElemPos < currSize)
        currElemPos++;
}

template <class T>
void ArrayList<T>::prev() {
    if (currElemPos != 0){
        currElemPos--;
    }
}

template <class T>
void ArrayList<T>::moveToStart() {
    currElemPos = 0;
}

template <class T>
void ArrayList<T>::moveToEnd() {
    currElemPos = currSize;
}

template <class T>
void ArrayList<T>::moveToPos(int const& n) {
    assert(n >= 0 && n <= currSize);
    currElemPos = n;
}

template <class T>
int ArrayList<T>::length() const {
    return currSize;
}

template <class T>
int ArrayList<T>::currPos() const {
    return currElemPos;
}

template <class T>
T ArrayList<T>::value() const {
    assert(currElemPos >=0 &&  currElemPos <= currSize); // No current element
    return arr[currElemPos];
}

template <class T>
void ArrayList<T>::remove(){
    assert(currSize != 0);


    if (currElemPos != currSize || currElemPos != currSize-1){
        for(int i = currElemPos; i < currSize-1; i++){
            arr[i] = arr[i+1];
        }
    }
    else {
        currElemPos--;
    }

    currSize--;
}

template <class T>
void ArrayList<T>::insert(T const& elem){
    //assert(currSize != 0)
    if(currSize >= maxSize){
        doubleArraySize();
    }
    for(int i = currSize; i > currElemPos; i--){
        arr[i] = arr[i-1];
    }
    arr[currElemPos] = elem;
    currSize++;
}

template <class T>
void ArrayList<T>::clear(){
    moveToStart();
    currSize = 0;
}

template <class T>
void ArrayList<T>::doubleArraySize(){
    maxSize *= 2;
    T* tempArr = new T[maxSize];
    for (int i = 0; i < currSize; i++){
        tempArr[i] = arr[i];
    }
    delete [] arr;   // Delete old arr
    arr = tempArr;  // Assign tempArr to arr
}

