#include <iostream>
using namespace std;


struct Node
{
    int Data;
    Node *Next;
};

struct LinkedList
{
    Node *pHead;
    Node *pTail;
};

void CreateLinkedList(LinkedList &List)
{
    List.pHead = List.pTail = nullptr;
    //NULL =  nullptr
}

Node* CreateNode(int value)
{
    Node *tmp = new Node{value, nullptr};
    // tmp->Data = value;
    // tmp->Next = nullptr;
    return tmp;
}

void addHead(LinkedList &List, int value)
{
    Node *tmp = CreateNode(value);

    if (List.pHead == nullptr && List.pTail == nullptr)
    {
        List.pHead = List.pTail = tmp;
    }
    else
    {
        tmp->Next = List.pHead;
        List.pHead = tmp;
    }
}

void addTail(LinkedList &List, int value)
{
    Node *tmp = CreateNode(value);

    if (List.pHead == nullptr && List.pTail == nullptr)
    {
        List.pHead = List.pTail = tmp;
    }
    else
    {
        List.pTail = tmp;
        tmp->Next = nullptr;
    }
}

void printList(LinkedList &List)
{
    Node *tmp = List.pHead;
    do
    {
        cout << tmp->Data << ' ';
        tmp->Next;
    }
    while (tmp != List.pTail);
}

int main()
{
    LinkedList LL;
    CreateLinkedList(LL);
    addHead(LL, 4);
    addHead(LL, 5);
    addHead(LL, 6);
    addHead(LL, 7);
    addHead(LL, 8);
    printList(LL);

    return 0;


}