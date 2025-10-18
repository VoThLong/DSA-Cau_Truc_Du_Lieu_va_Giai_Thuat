#ifndef Linked_List
#define Linked_List

#include <vector>

class LinkedList
{
    private:
        //CTDL Node
        struct Node 
        {
            int data;
            Node* next;
        };

        Node* pHead;
        Node* pTail;
        int count;
    public:
        LinkedList();
        ~LinkedList();
        void AddHead(int value);
        void AddTail(int value);
        void display();
        void AddPosition(int value, int pos);
        int getSize() const;
        int search(int value) const;
        std::vector<int> SearchAll(int value) const;
        void Remove(int pos);

//Bổ sung ý tưởng
        void SwapOnlyData(int pos1, int pos2);
        void SwapNode(int pos1, int pos2);
        void Combine(LinkedList& otherList);
        void QuickSortinLinkedList();
};

#endif