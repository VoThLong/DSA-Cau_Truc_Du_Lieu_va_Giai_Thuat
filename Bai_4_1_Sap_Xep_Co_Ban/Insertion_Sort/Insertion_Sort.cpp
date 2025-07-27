#include <iostream>
#include <vector>

using namespace std;

template <class Object>
void Swap(Object &a, Object &b)
{
    Object temp = a;
    a = b;
    b = temp;
}

template <class Object>
void coutvector(vector<Object> &arr)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <class Object>
void InsertionSort(vector<Object> &arr)
{
    for (size_t i = 1; i < arr.size(); i++)
    {
        int pos;
        Object x = arr[i];
        pos = i - 1;
        
        while (pos >= 0 && arr[pos] > x)
        {
        arr[pos + 1] = arr[pos];
        pos--;
        }
        arr[pos + 1] = x;
    }
}

int main()
{
    vector<int> arr = {1,5,6,9,7,2,3,4,8};
    InsertionSort(arr);
    coutvector(arr);
    return 0;
}