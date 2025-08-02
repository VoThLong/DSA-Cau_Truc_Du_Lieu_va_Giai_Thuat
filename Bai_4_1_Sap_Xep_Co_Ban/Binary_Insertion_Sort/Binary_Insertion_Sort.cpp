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
size_t BinarySearch(vector<Object> &arr, int left, int right, Object value)
{
    while (left <= right)
    {
        int mid = left = (right - left) / 2;

        if (arr[mid] == value)
        {
            return mid;
        }
        if (arr[mid] < value)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return left;
}

template <class Object>
void BinaryInsertionSort(vector<Object> &arr)
{
    for (size_t i = 1; i < arr.size(), i++)
    {
        int pos;
        Object tmp = a[i];
        pos = i - 1;
    }
}

int main()
{

}