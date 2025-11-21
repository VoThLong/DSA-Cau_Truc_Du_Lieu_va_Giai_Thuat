/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/
#include <iostream>
#include <stack>

#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node {
    int num;
    Node * next;
};

struct List {
    Node * head, * tail;
};

Node * CreateNode(int x) {
    Node * p = new Node;
    if (p == NULL) exit(1);
    p->num = x;
    p->next = NULL;
    return p;
}

void CreateList(List &l) {
    l.head = l.tail = NULL;
}

void AddHead(List &l, int x) {
    Node *p = CreateNode(x);
    if (l.head == NULL)
        l.tail = p;
    else
        p->next = l.head;
    l.head = p;
}

void AddTail(List &l, int x) {
    Node *p = CreateNode(x);
    if (l.head == NULL)
        l.head = p;
    else
        l.tail->next = p;
    l.tail = p;
}

Node * RemoveHead(List &l) {
    if (l.head == NULL)
        return NULL;
    Node * p = l.head;
    l.head = p->next;
    p->next = NULL;
    return p;
}

void PrintList(List l) {
    Node *p = l.head;
    while (p != NULL) {
        cout << p->num << ' ';
        p = p->next;
    }
}
void Sum(List, List, List &);

int main()
{
    List a, b, c;
    CreateList(a);
    CreateList(b);
    CreateList(c);
    int m, n, k;

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> k;
        AddTail(a, k);
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        AddTail(b, k);
    }

    Sum(a, b, c);
    PrintList(c);
    return 0;
}

void Sum(List a, List b, List &c) {
	
//###INSERT CODE HERE -
    stack<int> ListA;
    stack<int> ListB;

    Node* p = a.head;
    while (p != NULL) 
    {
        ListA.push(p->num);
        p = p->next;
    }

    Node * q = b.head;
    while (q != NULL) 
    {
        ListB.push(q->num);
        q = q->next;
    }

    int carry = 0;

    while (true)
    {
        if(ListA.empty() == 1 && ListB.empty() == 1)
            break;

        int numA;
        int numB;

        if (!ListA.empty())
        {
            numA = ListA.top();
            ListA.pop();
        }
        else
            numA = 0;
        if (!ListB.empty())
        {
            numB = ListB.top();
            ListB.pop();
        }
        else
            numB = 0;

        if (numA + numB + carry >= 10)
        {
            AddHead(c, (numA + numB + carry) % 10);
            carry = 1;
        }
        else
        {
            AddHead(c, numA + numB + carry);
            carry = 0;
        }
        if (ListA.empty() && ListB.empty() && carry == 1)
        {
            AddHead(c, 1);
            break;
        }
    }
}