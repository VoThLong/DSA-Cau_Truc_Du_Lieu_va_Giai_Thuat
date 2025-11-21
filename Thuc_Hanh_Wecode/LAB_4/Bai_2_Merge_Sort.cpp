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

// ###INSERT CODE HERE -

// -------------------------------------------------------------------
// BẮT ĐẦU THUẬT TOÁN MERGESORT O(n log n)
// -------------------------------------------------------------------

// BƯỚC 1: Hàm so sánh (Tái sử dụng logic ĐÚNG của bạn)
// Hàm này trả về 'true' nếu Hocsinh 'a' nên ĐỨNG TRƯỚC Hocsinh 'b'
bool is_a_smaller(Hocsinh a, Hocsinh b)
{
    if (a.Ten != b.Ten)
    {
        return (a.Ten < b.Ten); // Tên A-Z
    }
    if (a.Hodem != b.Hodem)
    {
        return (a.Hodem < b.Hodem); // Họ đệm A-Z
    }

    // So sánh tuổi (trẻ hơn đứng trước)
    if (a.Nam != b.Nam)
    {
        return (a.Nam > b.Nam); // Năm sinh lớn hơn (trẻ hơn)
    }
    if (a.Thang != b.Thang)
    {
        return (a.Thang > b.Thang); // Tháng lớn hơn
    }
    if (a.Ngay != b.Ngay)
    {
        return (a.Ngay > b.Ngay); // Ngày lớn hơn
    }

    return false; // Hai người hoàn toàn giống nhau (theo tiêu chí sort)
}

// BƯỚC 2: Hàm GỘP (Merge)
// Gộp 2 danh sách con (a và b) đã được sắp xếp thành 1 danh sách
Node *SortedMerge(Node *a, Node *b)
{
    Node *result = NULL; // Con trỏ đầu của danh sách kết quả

    // Trường hợp cơ sở (base case) của đệ quy
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    // So sánh a và b, chọn cái nhỏ hơn làm 'result'
    if (is_a_smaller(a->data, b->data))
    {
        result = a;
        // Gắn phần còn lại của 'result' bằng cách gọi đệ quy
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return result;
}

// BƯỚC 3: Hàm TÌM ĐIỂM GIỮA
// Dùng kỹ thuật "con trỏ chậm và con trỏ nhanh" (rùa và thỏ)
Node *GetMiddle(Node *head)
{
    if (head == NULL)
        return head;

    Node *slow = head;
    Node *fast = head->next;

    // 'fast' đi 2 bước, 'slow' đi 1 bước
    // Khi 'fast' đến cuối, 'slow' sẽ ở giữa
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow; // 'slow' đang là nút ở giữa
}

// BƯỚC 4: Hàm ĐỆ QUY CHIA VÀ TRỊ (Hàm chính của MergeSort)
// Hàm này sắp xếp danh sách và thay đổi con trỏ 'head'
// nên chúng ta dùng (Node** headRef) - con trỏ trỏ đến con trỏ head
void MergeSortRecursive(Node **headRef)
{
    Node *head = *headRef;
    Node *a; // Con trỏ đầu của nửa trái
    Node *b; // Con trỏ đầu của nửa phải

    // Base case: danh sách có 0 hoặc 1 phần tử (đã được sắp xếp)
    if (head == NULL || head->next == NULL)
    {
        return;
    }

    // 1. CHIA (Divide)
    Node *middle = GetMiddle(head); // Tìm điểm giữa
    a = head;                       // Nửa trái là từ 'head' đến 'middle'
    b = middle->next;               // Nửa phải là từ 'middle->next' đến hết

    middle->next = NULL; // Ngắt kết nối 2 nửa

    // 2. TRỊ (Conquer)
    // Đệ quy sắp xếp 2 nửa
    MergeSortRecursive(&a);
    MergeSortRecursive(&b);

    // 3. GỘP (Merge)
    // Gộp 2 nửa đã sắp xếp lại và cập nhật con trỏ head
    *headRef = SortedMerge(a, b);
}

// Hàm Sort() chính mà main() gọi
// Đây là điểm bắt đầu của thuật toán
void Sort(List &l)
{
    // Gọi hàm đệ quy, truyền vào ĐỊA CHỈ của con trỏ head
    MergeSortRecursive(&l.head);

    // Cập nhật lại l.tail (RẤT QUAN TRỌNG)
    // Vì 'tail' cũ có thể không còn đúng sau khi sắp xếp
    if (l.head == NULL)
    {
        l.tail = NULL;
    }
    else
    {
        // Duyệt đến cuối danh sách để tìm tail mới
        Node *p = l.head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        l.tail = p; // Gán 'tail' mới
    }
}
