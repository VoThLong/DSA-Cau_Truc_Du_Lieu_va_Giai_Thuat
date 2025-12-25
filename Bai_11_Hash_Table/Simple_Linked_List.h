#ifndef LinkedList_H
#define LinkedList_H

class LinkedList
{
private:
    struct Node
    {
        int data;
        Node *next;
    };
    Node *pHead;
    Node *pTail;
public:
    LinkedList();
    ~LinkedList();
    

}
#endif