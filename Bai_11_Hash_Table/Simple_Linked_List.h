#ifndef Simple_Linked_List_H
#define Simple_Linked_List_H

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
    void addHead(int value);
    void addTail(int value);

    

};
#endif