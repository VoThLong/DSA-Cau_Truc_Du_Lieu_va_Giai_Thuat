#include "BST.h"
#include <iostream>
using namespace std;



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

bool BST::SearchRecursive(Node *node, int value)
{
    if (node == nullptr) return false;

    if (node->data == value) return true;

    if (value < node->data)
        return SearchRecursive(node->left, value);
    else
        return SearchRecursive(node->right, value);

}

void BST::InOrderRecursive(Node *node)
{
    //Dieu kien dung de quy
    if (node == nullptr) return;

    if (node != nullptr)
    {
        //duyet het sang trai roi moi xuat gia tri
        InOrderRecursive(node->left);
        cout << node->data << " ";
        InOrderRecursive(node->right);
    }

}

void BST::PreOrderRecursive(Node *node)
{
    //Dieu kien dung
    if (node == nullptr) return;

    if (node != nullptr) 
    {
        //xuat gia tri truoc sau do sang trai
        cout << node->data << " ";
        PreOrderRecursive(node->left);
        PreOrderRecursive(node->right);
    }
}

void BST::PostOrderRecursive(Node *node)
{
    //Dieu kien dung
    if (node == nullptr) return;

    if (node != nullptr) 
    {
        //di den trai truoc, sau do den phai, roi moi toi 
        PostOrderRecursive(node->left);
        PostOrderRecursive(node->right);
        cout << node->data << " ";
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

bool BST::Search(int value)
{
    return SearchRecursive(this->root, value);
}

void BST::PrintInOrder()
{
    InOrderRecursive(this->root);
}

void BST::PrintPreOrder()
{
    PreOrderRecursive(this->root);
}

void BST::PrintPostOrder()
{
    PostOrderRecursive(this->root);
}
