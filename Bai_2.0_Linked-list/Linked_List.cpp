#include "Linked_List.h"
#include <iostream>
#include <vector>
using namespace std;

LinkedList::LinkedList()
{
    this->pHead = nullptr;
    this->pTail = nullptr;
    cout << "Một danh sách liên kết mới đã được tạo thành công!\n";
    this->count = 0;
}

LinkedList::~LinkedList()
{
    Node* tmp = this->pHead;
    while(tmp != nullptr)
    {
        this->pHead = this->pHead->next;
        delete tmp;
        tmp = this->pHead;
    }
    cout << "Danh sách liên kết đã được giải phóng!\n";
}

void LinkedList::AddHead(int value)
{
    //1. Tạo node mới
    Node* tmp = new Node{value, nullptr};

    //2. Kiểm tra danh sách có rỗng không?
    if (this->pHead == nullptr)
    {
        this-> pHead = tmp;
        this->pTail = tmp;
    }
    else
    {
        tmp->next = this->pHead;
        this->pHead = tmp;
    }
    this->count++;
}

void LinkedList::AddTail(int value)
{
    //1. Tạo node mới
    Node* tmp = new Node{value, nullptr};

    //2. Kiểm tra danh sách có rỗng không?
    if (this->pHead == nullptr)
    {
        this-> pHead = tmp;
        this->pTail = tmp;
    }
    else
    {
        this->pTail->next = tmp;
        this->pTail = tmp;
    }
    this->count++;
}

void LinkedList::display()
{
    Node* tmp = this->pHead;
    cout << "\n------------------------------------------------------\n";
    cout << "Danh sách liên kết: ";
    while (tmp != nullptr)
    {
        cout << tmp->data << " -> ";
        tmp = tmp->next;
    }
    cout << "NULL";
    cout << "\n------------------------------------------------------\n";
}

void LinkedList::AddPosition(int value, int pos)
{
    if (pos < 0 || pos > this->count)
    {
        cout << "Giá trị vị trí không hợp lệ! \n";
        return;
    }
    //chèn vào đầu
    if (pos == 0)
    {
        AddHead(value);
        return;
    }
    //chèn vào giữa 
    else if (pos == this->count)
    {
        AddTail(value);
        return;
    }
    else
    {
        Node* Previous_Node = this->pHead;
        for (int i = 0; i < pos - 1; i++)
        {
            Previous_Node = Previous_Node->next;
        }
        Node* newNode = new Node{value, nullptr};
        newNode->next = Previous_Node->next;
        Previous_Node->next = newNode;
        this->count++;
    }
    
}

int LinkedList::getSize() const
{
    return this->count;
}

int LinkedList::search(int value) const
{
    Node* current = this->pHead;
    int index = 0;
    while (current != nullptr)
    {
        if (current->data == value)
        {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}

std::vector<int> LinkedList::SearchAll(int value) const
{
    Node* current = this->pHead;
    int index = 0;
    std::vector<int> tmp;
    while (current != nullptr)
    {
        if (current->data == value)
        {
            tmp.push_back(index);
        }
        current = current->next;
        index++;
    }
    return tmp;
}

void LinkedList::Remove(int pos)
{
    if (pos < 0 || pos > this->count)
    {
        cout << "Giá trị vị trí không hợp lệ! \n";
        return;
    }
    if(pos == 0)
    {
        Node* NodeToDelete = this->pHead;
        this->pHead = this->pHead->next;
        delete NodeToDelete;
        if(this->pHead == nullptr)
        {
            this->pTail = nullptr;
        }
    }
    else
    {
        Node* Previous_Node = this->pHead;
        for (int i = 0; i < pos - 1; i++)
        {
            Previous_Node = Previous_Node->next;
        }
        Node* NodeToDelete = Previous_Node->next;
        Previous_Node->next = NodeToDelete->next;
        delete NodeToDelete;

        if(Previous_Node->next == nullptr)
        {
            this->pTail = Previous_Node;
        }
    }
    this->count--;
}

//Bổ sung ý tưởng
void LinkedList::SwapOnlyData(int pos1, int pos2)
{
    if (pos1 < 0 || pos1 >= this->count || pos2 < 0 || pos2 >= this->count)
    {
        cout << "Giá trị vị trí không hợp lệ! \n";
        return;
    }
    if (pos1 == pos2)
    {
        return; // Không cần hoán đổi nếu hai vị trí giống nhau
    }

    Node* node1 = this->pHead;
    Node* node2 = this->pHead;

    for (int i = 0; i < pos1; i++)
    {
        node1 = node1->next;
    }
    for (int i = 0; i < pos2; i++)
    {
        node2 = node2->next;
    }

    // Hoán đổi dữ liệu giữa hai nút
    int temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
}

void LinkedList::SwapNode(int pos1, int pos2)
{
    if (pos1 < 0 || pos1 >= this->count || pos2 < 0 || pos2 >= this->count)
    {
        cout << "Giá trị vị trí không hợp lệ! \n";
        return;
    }
    if (pos1 == pos2)
    {
        return; // Không cần hoán đổi nếu hai vị trí giống nhau
    }

    // Đảm bảo pos1 luôn nhỏ hơn pos2 để dễ xử lý
    if (pos1 > pos2)
    {
        std::swap(pos1, pos2);
    }

    Node* prev1 = nullptr;
    Node* curr1 = this->pHead;
    for (int i = 0; i < pos1; i++)
    {
        prev1 = curr1;
        curr1 = curr1->next;
    }

    Node* prev2 = nullptr;
    Node* curr2 = this->pHead;
    for (int i = 0; i < pos2; i++)
    {
        prev2 = curr2;
        curr2 = curr2->next;
    }

    // Nếu curr1 hoặc curr2 là đầu danh sách
    if (prev1 != nullptr)
    {
        prev1->next = curr2;
    }
    else
    {
        this->pHead = curr2;
    }

    if (prev2 != nullptr)
    {
        prev2->next = curr1;
    }
    else
    {
        this->pHead = curr1;
    }

    // Hoán đổi con trỏ next của curr1 và curr2
    Node* temp = curr2->next;
    curr2->next = curr1->next;
    curr1->next = temp;

    // Cập nhật pTail nếu cần thiết
    if (curr1->next == nullptr)
    {
        this->pTail = curr1;
    }
    if (curr2->next == nullptr)
    {
        this->pTail = curr2;
    }
}

void LinkedList::Combine(LinkedList& otherList)
{
    if (this == &otherList)
    {
        return; // Tránh kết hợp với chính nó
    }
    if (otherList.pHead == nullptr)
    {
        return; // Danh sách khác rỗng, không cần kết hợp
    }

    // Kết hợp danh sách khác vào danh sách hiện tại
    this->pTail->next = otherList.pHead;
    this->pTail = otherList.pTail;
    this->count += otherList.count;

    // Đặt lại danh sách khác
    otherList.pHead = nullptr;
    otherList.pTail = nullptr;
    otherList.count = 0;
}