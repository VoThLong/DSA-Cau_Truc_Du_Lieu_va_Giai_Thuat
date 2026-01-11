#include <iostream>
#include "HashTable.h"

// Constructor
HashTable::HashTable(int size) {
    this->M = size;
    table.resize(M); // Tạo M bucket rỗng
}

// Hàm băm
int HashTable::hashFunction(int key) {
    return key % M;
}

// Thêm
void HashTable::insertItem(int key) {
    int index = hashFunction(key);
    table[index].addTail(key);
}

// Xóa
void HashTable::deleteItem(int key) {
    int index = hashFunction(key);
    table[index].deleteNode(key);
}

// Hiển thị
void HashTable::displayHash() {
    for (int i = 0; i < M; i++) {
        std::cout << "Bucket " << i << ": ";
        table[i].printList();
    }
}
