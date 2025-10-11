#include <iostream>
#include "Queue.h"
using namespace std;

template <class T>
Queue<T>::Queue()
{
    frontIndex = 0;
    rearIndex = -1;
    count = 0;
}

template <class T>
bool Queue<T>::isEmpty()
{
    return count == 0;
}

template <class T>
bool Queue<T>::isFull()
{
    return count == MAX_SIZE;
}

template <class T>
void Queue<T>::EnQueue(T value)
{
    if (isFull()) return;
    rearIndex 
}

template <class T>
void Queue<T>:: DeQueue()
{
    if (isEmpty()) return;
    frontIndex = (frontIndex + 1) % MAX_SIZE;
    count--;
}

template <class T>
T Queue<T>::Front()
{
    if (isEmpty()) return T();
    return arr[frontIndex];
}

template <class T>
int Queue<T>::Size()
{
    return count;
}