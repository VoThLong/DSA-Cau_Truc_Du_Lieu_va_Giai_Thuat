#include <iostream>
#include <vector>

using namespace std;

template <class T>
void Swap(T &a, T &b)
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
void QuickSortRecursive(vector<T> &arr, int left, int right)
{
    int i = left, j = right;

    T pivot = arr[(i + j) / 2];

    while (i <= j)
    {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j)
        {
            Swap(arr[i], arr[j]);
            cout << "Swap: arr[" << i << "] and arr[" << j << "] → ";
            PrintVector(arr);   // in mảng sau mỗi swap
            i++;
            j--;
        }
    }
    if (left < j) QuickSortRecursive(arr, left, j);
    if (i < right) QuickSortRecursive(arr, i, right);
}

template <class T>
void QuickSort(vector<T> &arr) {
    if (!arr.empty())
        QuickSortRecursive(arr, 0, (int)arr.size() - 1);
}


int main()
{
    vector<int> a = {8, 7, 2, 1, 0, 9, 6, 4, 3, 5};

    cout << "Original array: ";
    PrintVector(a);

    QuickSort(a);
    cout << "Sorted array:   ";
    PrintVector(a);
    return 0;
}