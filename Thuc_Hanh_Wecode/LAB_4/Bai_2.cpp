/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
[
]
###End banned keyword*/
#include <iostream>

using namespace std;

struct Hocsinh
{
    string Hodem, Ten;
    bool Gioitinh;
    int Ngay, Thang, Nam;
    double Toan, Van, Ly, Hoa, Anh, Sinh;
};

void InputElement(Hocsinh &x)
{
    getline(cin >> ws, x.Hodem);
    getline(cin >> ws, x.Ten);
    cin >> x.Gioitinh;
    cin >> x.Ngay >> x.Thang >> x.Nam;
    cin >> x.Toan >> x.Van >> x.Ly >> x.Hoa >> x.Anh >> x.Sinh;
}

void OutputElement(Hocsinh hs)
{
    cout << hs.Hodem
         << ' ' << hs.Ten
         << '\t' << hs.Gioitinh
         << '\t' << hs.Ngay
         << '/' << hs.Thang
         << '/' << hs.Nam
         << '\t' << hs.Toan
         << '\t' << hs.Van
         << '\t' << hs.Ly
         << '\t' << hs.Hoa
         << '\t' << hs.Anh
         << '\t' << hs.Sinh << endl;
    ;
}

struct Node
{
    Hocsinh data;
    Node *next;
};

struct List
{
    Node *head, *tail;
};

Node *CreateNode(Hocsinh x)
{
    Node *p = new Node;
    if (p == NULL)
        exit(1);
    p->data = x;
    p->next = NULL;
    return p;
}

void CreateList(List &l)
{
    l.head = l.tail = NULL;
}

void AddHead(List &l, Hocsinh x)
{
    Node *p = CreateNode(x);
    if (l.head == NULL)
        l.tail = p;
    else
        p->next = l.head;
    l.head = p;
}

void AddTail(List &l, Hocsinh x)
{
    Node *p = CreateNode(x);
    if (l.head == NULL)
        l.head = p;
    else
        l.tail->next = p;
    l.tail = p;
}

Node *RemoveHead(List &l)
{
    if (l.head == NULL)
        return NULL;
    Node *p = l.head;
    l.head = p->next;
    p->next = NULL;
    return p;
}

void PrintList(List l)
{
    Node *p = l.head;
    while (p != NULL)
    {
        OutputElement(p->data);
        p = p->next;
    }
}

void Sort(List &);

int main()
{
    List l;
    int n;
    Hocsinh hs;

    CreateList(l);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        InputElement(hs);
        AddTail(l, hs);
    }

    Sort(l);
    PrintList(l);
    return 0;
}

// ###INSERT CODE HERE -

void swap_node(Node *a, Node *b)
{
    Hocsinh temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void Sort(List &l) // Sử dụng Bubble sort
{
    // Chỗ này bạn gõ 2 lần, tôi sửa lại 1 lần nhé
    if (l.head == NULL || l.head->next == NULL)
    {
        return;
    }
    
    // Vòng lặp p (ĐÚNG)
    for (Node *p = l.head; p->next != NULL; p = p->next)
    {
        // Vòng lặp q (ĐÃ SỬA)
        // Điều kiện phải là "q != NULL" để nó chạy đến hết danh sách
        for (Node *q = p->next; q != NULL; q = q->next) 
        {
            bool compare = false;

            // Logic so sánh rất thông minh của bạn (ĐÚNG)
            if (q->data.Ten != p->data.Ten)
            {
                compare = (q->data.Ten < p->data.Ten);
            }
            else if (q->data.Hodem != p->data.Hodem)
            {
                compare = (q->data.Hodem < p->data.Hodem);
            }
            else if (q->data.Nam != p->data.Nam)
            {
                compare = (q->data.Nam > p->data.Nam);  // Năm lớn hơn = trẻ hơn
            }
            else if (q->data.Thang != p->data.Thang)
            {
                compare = (q->data.Thang > p->data.Thang);  // Tháng lớn hơn = trẻ hơn
            }
            else
            {
                // Chỉ so sánh Ngày khi Tên, Họ, Năm, Tháng đều bằng nhau
                compare = (q->data.Ngay > p->data.Ngay);  // Ngày lớn hơn = trẻ hơn
            }

            if (compare)
            {
                swap_node(p, q);
            }
        }
    }
}