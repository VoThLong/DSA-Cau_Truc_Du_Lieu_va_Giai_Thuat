/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
[
]
###End banned keyword*/
#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct List
{
    Node *head, *tail;
};

Node *CreateNode(int x)
{
    Node *p = new Node;
    if (p == NULL)
        exit(1);
    p->next = NULL;
    p->data = x;
    return p;
}

void CreateList(List &l)
{
    l.head = l.tail = NULL;
}

void AddHead(List &l, int x)
{
    Node *p = CreateNode(x);
    if (l.head == NULL)
        l.tail = p;
    else
        p->next = l.head;
    l.head = p;
}

void AddTail(List &l, int x)
{
    Node *p = CreateNode(x);
    if (l.head == NULL)
        l.head = p;
    else
        l.tail->next = p;
    l.tail = p;
}

// ###INSERT CODE HERE -
void PrintList(List l)
{
    Node *p = l.head;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

int main()
{
    List l;
    CreateList(l);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x % 2 == 0)
        {                  // Nếu là số chẵn
            AddHead(l, x); // Thêm vào đầu để đảo ngược thứ tự
        }
    }

    PrintList(l);

    return 0;
}