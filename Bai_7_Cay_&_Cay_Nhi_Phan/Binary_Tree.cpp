#include "Binary_Tree.h"
#include <iostream>

template <class T>
Binary_Tree<T>::Binary_Tree()
{
    this->root = nullptr;
}

template <class T>
typename Binary_Tree<T>::Node *Binary_Tree<T>::createNode(T val)
{
    Node *newNode = new Node();
    newNode->data = val;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

template <class T>
inline void Binary_Tree<T>::insert_recursive(Node *&node, int val)
{
    if (node == nullptr)
    {
        node = createNode(val);
    }
}

