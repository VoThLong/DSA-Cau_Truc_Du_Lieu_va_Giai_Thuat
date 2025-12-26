#include "Simple_Linked_List.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList()
{
    this->pHead = nullptr;
    this->pTail = nullptr;
}

void LinkedList::addHead(int value)
{
    Node *tmp = new Node{value, nullptr};

    if(pHead == nullptr)
    {
        this->pHead = tmp;
        this->pTail = tmp;
    }
    else
    {
        tmp->next = this->pHead;
        this->pHead = tmp;
    }
}