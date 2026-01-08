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
        List.pTail->Next = tmp;
        List.pTail = tmp;
    }
}

void printList(LinkedList &List)
{
    Node *tmp = List.pHead;
    while (tmp != nullptr)
    {
        cout << tmp->Data << ' ';
        tmp = tmp->Next;
    }
}

bool Search(LinkedList &List, int value)
{
    Node *crr = List.pHead;
    while (crr != nullptr)
    {
        if (crr->Data == value)
        {
            return true;
        }
        crr = crr->Next;
    }
    return false;
}

int getsize(LinkedList &List)
{   
    int size = 0;
    Node* crr = List.pHead;
    while (crr != nullptr)
    {
        crr = crr->Next;
        size++;
    }
    return size;
}

void addPos(LinkedList &List, int value, int index)
{
    if (index == 0)
    {
        addHead(List, value);
    }
    else if (index == getsize(List))
    {
        addTail(List, value);
    }

    if (index > 0 && index < getsize(List) )
    {

        Node *tmp = CreateNode(value);
        Node *crr = List.pHead;
    
        for (int i = 0; i < index - 1; i++)
        {
            crr = crr->Next;
        }
        tmp->Next = crr->Next;
        crr->Next = tmp;

    }
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
    addTail(LL, 3);
    printList(LL);
    cout << endl;
    bool i = Search(LL, 14);
    if (i != 0) cout << "true\n";
    else cout << "false\n";
    cout << getsize(LL) << endl;
    addPos(LL, 10, 4);
    printList(LL);

    return 0;


}