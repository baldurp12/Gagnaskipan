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
    return NULL;
}

template <class T>
BinaryNode<T>* BinarySearchTree<T>::minNode() const
{
    return NULL;
}

template <class T>
void BinarySearchTree<T>::insert(const T& anItem)
{
    insertAt(this->root, anItem);
}

template <class T>
void BinarySearchTree<T>::remove(const T& anItem)
{
    BinaryNode<T>* remNode = findAt(this->root, anItem);
    if(remNode != NULL)
    {
        removeAt(remNode, anItem);
    }
    else
    {
        cout << "Nothing was removed" << endl;
    }

}

template <class T>
BinaryNode<T>* BinarySearchTree<T>::maxNode(BinaryNode<T>* node) const
{

}

template <class T>
BinaryNode<T>* BinarySearchTree<T>::minNode(BinaryNode<T>* node) const
{

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
        removeNode(node);
}

template <class T>
void BinarySearchTree<T>::removeNode(BinaryNode<T>*& node)
{
    cout << "Attempted to remove " << node->item << endl;
    if(node->isLeaf())
    {
        delete node;
        cout << "Node was a leaf and has been terminated" << endl;
    }
    else if(node->leftChild == NULL)
    {
        BinaryNode<T>* remNode = new BinaryNode<T>;
        remNode = node;
        node = node->rightChild;
        delete remNode;
        cout << "rightChild was removed" << endl;
    }
    else if(node->rightChild == NULL)
    {
        BinaryNode<T>* remNode = new BinaryNode<T>;
        remNode = node;
        node = node->leftChild;
        delete remNode;
        cout << "leftChild was removed" << endl;
    }
    else
    {
        //node->item = processLeftmost(node->rightChild);
        cout << "Shoulde have listened to your mom" << endl;
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
