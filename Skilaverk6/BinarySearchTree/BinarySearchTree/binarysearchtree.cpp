#include "binarysearchtree.h"
#include "binarytree.cpp"

template <class T>
BinarySearchTree<T>::BinarySearchTree() : BinaryTree<T>()
{
}

template <class T>
BinarySearchTree<T>::BinarySearchTree(const T& rootItem) : BinaryTree<T>(rootItem)
{
    this->root->leftChild = NULL;
    this->root->rightChild = NULL;
    this->root->item = rootItem;
}

template <class T>
BinarySearchTree<T>::~BinarySearchTree()
{
}

template <class T>
BinaryNode<T>* BinarySearchTree<T>::maxNode() const
{
    return maxNode(this->root);
}

template <class T>
BinaryNode<T>* BinarySearchTree<T>::minNode() const
{
    return minNode(this->root);
}

template <class T>
void BinarySearchTree<T>::insert(const T& anItem)
{
    insertAt(this->root, anItem);
}

template <class T>
void BinarySearchTree<T>::remove(const T& anItem)
{
    removeAt(this->root, anItem);
}

template <class T>
BinaryNode<T>* BinarySearchTree<T>::maxNode(BinaryNode<T>* node) const
{
    if(node == NULL)
    {
        return NULL;
    }
    else if(node->rightChild == NULL ){
        return node;
    }
    else
    {
        return maxNode(node->rightChild);
    }
}

template <class T>
BinaryNode<T>* BinarySearchTree<T>::minNode(BinaryNode<T>* node) const
{
    if(node == NULL)
    {
        return NULL;
    }
    else if(node->leftChild == NULL ){
        return node;
    }
    else
    {
        return minNode(node->leftChild);
    }
}

template <class T>
void BinarySearchTree<T>::insertAt(BinaryNode<T>*& node, const T& anItem)
{
    if(node == NULL)
    {
        node = new BinaryNode<T>(anItem);
    }
    else if(anItem < node->item)
    {
        insertAt(node->leftChild, anItem);
    }
    else if(anItem > node->item)
    {
        insertAt(node->rightChild, anItem);
    }
}

template <class T>
void BinarySearchTree<T>::removeAt(BinaryNode<T>*& node, const T& anItem)
{
    if(node == NULL){
        //Víí
    }
    else if (anItem == node->item) { // Then found
        removeNode(node);
    }
    else if (anItem < node->item) {  // Search in the left tree
       removeAt(node->leftChild, anItem);
    }
    else {                            // Search in the right tree
        removeAt(node->rightChild, anItem);
    }
}

template <class T>
void BinarySearchTree<T>::removeNode(BinaryNode<T>*& node)
{
    if(node->isLeaf())
    {
        delete node;
        node = NULL;
    }
    else if(node->leftChild == NULL)
    {
        BinaryNode<T>* tempDel = node->rightChild;
        delete node;
        node = tempDel;
    }
    else if(node->rightChild == NULL)
    {
        BinaryNode<T>* tempDel = node->leftChild;
        delete node;
        node = tempDel;
    }
    else
    {
        node->item = processLeftmost(node->rightChild);
    }
}

template <class T>
T BinarySearchTree<T>::processLeftmost(BinaryNode<T>*& node)
{
/*  BinaryNode<T>* temp = new BinaryNode<T>;
    temp = minNode(node);
    T tempItem = temp->item;
    delete temp;
    return tempItem
*/

    if(node->leftChild != NULL){
        return processLeftmost(node->leftChild);
    }
    else {
        T tempItem = node->item;
        removeNode(node);
        return tempItem;
    }
}

template <class T>
BinaryNode<T>* BinarySearchTree<T>::findAt(BinaryNode<T> * node, const T& anItem) const
// Retrieves an item starting searching at node
{
    if (node == NULL) {      // Then the item was not found
        return NULL;
    }
    else if (anItem == node->item) { // Then found
        return node;
    }
    else if (anItem < node->item) {  // Search in the left tree
        return (findAt(node->leftChild, anItem));
    }
    else {                            // Search in the right tree
        return (findAt(node->rightChild, anItem));
    }
}

template <class T>
BinaryNode<T>* BinarySearchTree<T>::find(const T& anItem) const // Retrieves the node corresponding to the item. If not found, returns null
{
    return (findAt(BinaryTree<T>::root, anItem));
}
