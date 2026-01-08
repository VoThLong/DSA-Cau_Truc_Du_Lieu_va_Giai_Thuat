#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include "Simple_Linked_List.h"

class HashTable {
private:
    int M; // Kích thước bảng
    std::vector<LinkedList> table;

    int hashFunction(int key);

public:
    HashTable(int size); // Constructor
    
    void insertItem(int key);
    void deleteItem(int key);
    void displayHash();
};

#endif