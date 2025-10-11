#ifndef Queue_H
#define Queue_H

template <class T>
class Queue
{
private:
    T arr[MAX_SIZE];
    int frontIndex;
    int rearIndex;
    int count; // Số lượng phần tử hiện tại trong hàng đợi

public:
    Queue();
    bool isEmpty();
    bool isFull();
    void EnQueue(T valude);
    void DeQueue();
    T Front();
    int Size();

};

#include "Queue.cpp"

#endif