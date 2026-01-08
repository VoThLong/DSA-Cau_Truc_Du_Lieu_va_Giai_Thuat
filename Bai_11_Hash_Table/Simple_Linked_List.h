#ifndef SIMPLE_LINKED_LIST_H
#define SIMPLE_LINKED_LIST_H

#include <iostream>

class LinkedList
{
private:
    struct Node
    {
        int data;
        Node *next;
        // Constructor node cho tiện
        Node(int val) : data(val), next(NULL) {}
    };
    Node *pHead;
    Node *pTail;

public:
    LinkedList();
    ~LinkedList();

    // --- BỔ SUNG CÁC HÀM NÀY ---
    void addTail(int data);   // Thêm vào cuối
    bool search(int data);    // Tìm kiếm
    void deleteNode(int data); // Xóa node
    void printList();         // In ra để debug xem code chạy đúng không
};

#endif