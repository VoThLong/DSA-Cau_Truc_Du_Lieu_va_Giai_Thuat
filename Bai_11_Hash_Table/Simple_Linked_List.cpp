#include "Simple_Linked_List.h"

// 1. Constructor: Khởi tạo list rỗng
LinkedList::LinkedList() {
    pHead = NULL;
    pTail = NULL;
}

// 2. Destructor: Dọn dẹp bộ nhớ khi hủy list
LinkedList::~LinkedList() {
    Node* node = pHead;
    while (node != NULL) {
        Node* nextNode = node->next;
        delete node;
        node = nextNode;
    }
}

// 3. Hàm thêm vào cuối (Insert)
void LinkedList::addTail(int data) {
    Node* newNode = new Node(data);
    if (pHead == NULL) {
        pHead = pTail = newNode;
    } else {
        pTail->next = newNode;
        pTail = newNode;
    }
}

// 4. Hàm tìm kiếm (Search) -> Trả về true nếu tìm thấy
bool LinkedList::search(int data) {
    Node* temp = pHead;
    while (temp != NULL) {
        if (temp->data == data) return true;
        temp = temp->next;
    }
    return false;
}

// 5. Hàm xóa (Delete) - Logic khó nhất
void LinkedList::deleteNode(int data) {
    // Trường hợp list rỗng
    if (pHead == NULL) return;

    // Trường hợp số cần xóa nằm ngay đầu (Head)
    if (pHead->data == data) {
        Node* temp = pHead;
        pHead = pHead->next;
        if (pHead == NULL) pTail = NULL; // Nếu xóa xong list rỗng
        delete temp;
        return;
    }

    // Trường hợp nằm ở giữa hoặc cuối
    Node* temp = pHead;
    while (temp->next != NULL) {
        if (temp->next->data == data) {
            Node* nodeToDelete = temp->next;
            temp->next = nodeToDelete->next;
            
            // Nếu xóa node cuối thì phải cập nhật pTail
            if (nodeToDelete == pTail) {
                pTail = temp;
            }
            
            delete nodeToDelete;
            return; // Xóa xong thì thoát
        }
        temp = temp->next;
    }
}

// 6. Hàm in danh sách (Để kiểm tra)
void LinkedList::printList() {
    Node* temp = pHead;
    while (temp != NULL) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL" << std::endl;
}