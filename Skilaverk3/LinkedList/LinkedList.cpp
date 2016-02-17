#include "LinkedList.h"

template<class T>
LinkedList<T>::LinkedList(){
    header = new Node<T>;
    trailer = new Node<T>;
    init();
}

template<class T>
LinkedList<T>::LinkedList(LinkedList<T>& lis){
    header = new Node<T>;
    trailer = new Node<T>;
    init();
    for(Node<T>* iter = lis.header->getNext(); iter != lis.trailer; iter = iter->getNext()){
        append(iter->getData());
    }
}

template<class T>
LinkedList<T>::~LinkedList(){
    removeAll();
    delete header;
    delete trailer;
}

template<class T>
void LinkedList<T>::next(){
    if(currNode != trailer){
        currNode = currNode->getNext();
    }
}

template<class T>
void LinkedList<T>::prev(){
    if(currNode != header->getNext()){
        currNode = currNode->getPrev();
    }
}

template<class T>
void LinkedList<T>::moveToStart(){
    currNode = header->getNext();
}

template<class T>
void LinkedList<T>::moveToEnd(){
    currNode = trailer;
}

template<class T>
void LinkedList<T>::moveToPos(int pos){
    moveToStart();
    for(int i = 0; i < pos; i++){
        next();
    }
}

template<class T>
int LinkedList<T>::length() const{
    return currSize;
}

template<class T>
T LinkedList<T>::value() const{
    if(currNode == trailer || currNode == header)
    {
            return 0;
    }
    else{
        return currNode->getData();
    }
}

template<class T>
bool LinkedList<T>::empty() const{
    if(header->getNext() == trailer){
        return true;
    }
    else{
        return false;
    }
}

template<class T>
void LinkedList<T>::append (T elem){
    Node<T>* newNode = new Node<T>;
    Node<T>* tempPtr = trailer->getPrev();

    newNode->setValue(elem);
    newNode->setNext(trailer);
    newNode->setPrev(tempPtr);

    tempPtr->setNext(newNode);
    trailer->setPrev(newNode);
    currSize++;
    if(currNode == trailer){
        currNode = newNode;
    }
}

template<class T>
void LinkedList<T>::insert (const T& elem){
    Node<T>* newNode = new Node<T>;
    Node<T>* tempPtr = currNode->getPrev();

    newNode->setValue(elem);
    newNode->setNext(currNode);
    newNode->setPrev(tempPtr);

    tempPtr->setNext(newNode);
    currNode->setPrev(newNode);

    currNode = newNode;
    currSize++;
}

template<class T>
T LinkedList<T>::remove(){

    if(currNode != trailer){
        T tempT = currNode->getData();
        Node<T>* tempPtr = currNode->getNext();

        currNode->getNext()->setPrev(currNode->getPrev());
        currNode->getPrev()->setNext(currNode->getNext());

        delete currNode;

        currNode = tempPtr;

        currSize--;
        return tempT;
    }
    return 0;
}

template<class T>
void LinkedList<T>::clear(){
    removeAll();
    init();
}

template<class T>
Node<T>* LinkedList<T>::end() const{
    return trailer;
}

template<class T>
Node<T>* LinkedList<T>::getCurrNode() const{
    return currNode;
}

template<class T>
void LinkedList<T>::insert(Node<T>* beforeMe, const T& elem){
    currNode = beforeMe;
    insert(elem);
}

template<class T>
void LinkedList<T>::removeAll(){
    currNode = header->getNext();
    while(getCurrNode() != trailer){
        remove();
    }

}

template <class T>
void LinkedList<T>::init(){
    currSize = 0;
    header->setNext(trailer);
    header->setPrev(NULL);
    trailer->setPrev(header);
    trailer->setNext(NULL);
    currNode = trailer;
}
