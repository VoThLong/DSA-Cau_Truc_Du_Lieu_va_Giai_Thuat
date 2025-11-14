/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
[
]
###End banned keyword*/
#include <iostream>

using namespace std;

// ###INSERT CODE HERE -
struct Node
{
    int data;
    Node *next;
};

int main()
{
    int n;
    cin >> n;

    // Tạo danh sách liên kết để lưu các số chẵn
    Node *head = NULL;
    Node *tail = NULL;
    int count = 0;

    // Đọc dữ liệu và lưu các số chẵn vào danh sách
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;

        if (temp % 2 == 0)
        {
            Node *newNode = new Node;
            newNode->data = temp;
            newNode->next = NULL;

            if (head == NULL)
            {
                head = tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
            count++;
        }
    }

    // Tính vị trí chính giữa
    int middlePos = (count - 1) / 2;

    // Duyệt đến vị trí chính giữa
    Node *p = head;
    for (int i = 0; i < middlePos; i++)
    {
        p = p->next;
    }

    cout << p->data;

    // Giải phóng bộ nhớ
    while (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}