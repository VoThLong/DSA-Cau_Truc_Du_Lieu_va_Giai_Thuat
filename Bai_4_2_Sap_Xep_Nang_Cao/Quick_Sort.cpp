#include <iostream>
#include <vector>

using namespace std;

template <class T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <class T>
void PrintVector(const vector<T> &arr)
{
    for (const auto &elem : arr)
    {
        cout << elem << " ";
    }
    cout << endl;
}

template <class T>
void QuickSort(vector<T> &arr)
{
    int i = 0, j = (int)arr.size() - 1;

    T pivot = arr[(i + j) / 2];

    while (i <= j)
    {
        
    }
}