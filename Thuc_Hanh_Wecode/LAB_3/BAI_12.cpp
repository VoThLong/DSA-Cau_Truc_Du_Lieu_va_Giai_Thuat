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
    int Maso;
    string Hoten;
    int Namsinh;
    bool Gioitinh;
    double TBK;
};
void Input(Hocsinh &x)
{
    cin >> x.Maso;
    getline(cin >> ws, x.Hoten);
    cin >> x.Namsinh;
    cin >> x.Gioitinh;
    cin >> x.TBK;
}
void Output(Hocsinh hs)
{
    cout << '[' << hs.Maso << "\t" << hs.Hoten << "\t" << hs.Gioitinh << "\t" << hs.Namsinh << "\t" << hs.TBK << "]\n";
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

void AddTail(List &l, Hocsinh x)
{
    Node *p = CreateNode(x);
    if (l.head == NULL)
    {
        l.head = l.tail = p;
    }
    else
    {
        l.tail->next = p;
        l.tail = p;
    }
}

void DeleteIndex(List &l, int i);

int main()
{
    int n, m, index;
    Hocsinh hs;
    List l;
    CreateList(l);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Input(hs);
        AddTail(l, hs);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> index;
        DeleteIndex(l, index);
    }

    Node *p = l.head;
    while (p != NULL)
    {
        Output(p->data);
        p = l.head->next;
        delete l.head;
        l.head = p;
    }

    return 0;
}

void DeleteIndex(List &l, int i)
{

    // ###INSERT CODE HERE -
    if (l.head == NULL || i < 0)
    {
        return;
    }

    // Trường hợp xóa phần tử đầu tiên (index = 0)
    if (i == 0)
    {
        Node *temp = l.head;
        l.head = l.head->next;

        // Nếu danh sách chỉ có 1 phần tử
        if (l.head == NULL)
        {
            l.tail = NULL;
        }

        delete temp;
        return;
    }

    // Tìm node trước node cần xóa
    Node *p = l.head;
    int count = 0;

    while (p != NULL && count < i - 1)
    {
        p = p->next;
        count++;
    }

    // Kiểm tra nếu index vượt quá giới hạn
    if (p == NULL || p->next == NULL)
    {
        return;
    }

    // Xóa node tại vị trí i
    Node *temp = p->next;
    p->next = temp->next;

    // Cập nhật tail nếu xóa phần tử cuối
    if (temp == l.tail)
    {
        l.tail = p;
    }

    delete temp;
}