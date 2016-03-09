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
    BinaryNode<T>* current = node;
    while (current->rightChild != NULL)
        current = current->rightChild;
    return current;
}

template <class T>
BinaryNode<T>* BinarySearchTree<T>::minNode(BinaryNode<T>* node) const
{
    BinaryNode<T>* current = node;
    while(current->leftChild != NULL)
        current = current->leftChild;
    return current;
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
    else
    {
        cout << "Insert failed, perhaps on purpose" << endl;
    }
}

template <class T>
void BinarySearchTree<T>::removeAt(BinaryNode<T>*& node, const T& anItem)
{
    if (anItem == node->item) { // Then found
        removeNode(node);
    }
    else if (anItem < node->item) {  // Search in the left tree
       removeAt(node->leftChild, anItem);
    }
    else {                            // Search in the right tree
        removeAt(node->rightChild, anItem);
    }}

template <class T>
void BinarySearchTree<T>::removeNode(BinaryNode<T>*& node)
{
    cout << "Attempted to remove " << node->item << endl;

    if(node->isLeaf())
    {
        delete node;
        node = NULL;
        cout << "Node was a leaf and has been terminated" << endl;
    }
    else if(node->leftChild == NULL)
    {
        node = node->rightChild;
        cout << "rightChild was removed" << endl;
    }
    else if(node->rightChild == NULL)
    {
        node = node->leftChild;
        cout << "leftChild was removed" << endl;
    }
    else
    {
        //node->item = processLeftmost(node->rightChild);
        cout << "Should have listened to your mom" << endl;
    }
}

template <class T>
T BinarySearchTree<T>::processLeftmost(BinaryNode<T>*& node)
{

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
