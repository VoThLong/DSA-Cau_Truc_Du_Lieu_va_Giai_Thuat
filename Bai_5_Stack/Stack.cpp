#include "Stack.h"

#include <iostream>
using namespace std;

template <class T>
Stack<T>::Stack()
{
    TopIndex = -1;
}

template <class T>
bool Stack<T>::isEmpty()
{
    if (TopIndex == -1)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

template <class T>
bool Stack<T>::isFull()
{
    if (TopIndex == MAX_SIZE - 1)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

template  <class T>
void Stack<T>::push(T value)
{
    this->arr[++TopIndex] = value;
}

template <class T>
void Stack<T>::pop()
{
    this->TopIndex--;
}

template <class T>
T Stack<T>::top()
{
    return this->arr[TopIndex];
}

template <class T>
void Stack<T>::print()
{
    for (int i = TopIndex; i >= 0; i--)
    {
        cout << this->arr[i] << " ";
    }
    cout << endl;
}