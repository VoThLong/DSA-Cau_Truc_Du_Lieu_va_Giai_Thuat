#include "BST.h"
#include <iostream>



BST::Node *BST::createnode(int value)
{
    Node *p = new Node;
    p->data  = value;
    p->left = nullptr;
    p->right =  nullptr;
    return p;
}

void BST::insert_recursive(Node *&node, int value)
{
    if (node == nullptr)
    {
        node = createnode(value);
    }
    if (node != nullptr && value < node->data)
    {
        insert_recursive(node->left, value);
    }
    if (node != nullptr && value > node->data)
    {
        insert_recursive(node->right, value);
    }
}

BST::BST()
{
    this->root = nullptr;
}

//them gia tri bat dau duyet tu node goc
void BST::insert(int value)
{
    insert_recursive(this->root, value);
}

