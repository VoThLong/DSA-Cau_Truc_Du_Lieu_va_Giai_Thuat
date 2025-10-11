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
void Input(vector<Object> &arr) {
    for(int i = 0; i < arr.size(); i++) {
        cin >> arr[i];
    }
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
        coutvector(arr);
        }
        arr[pos + 1] = x;
        coutvector(arr);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    Input(arr);
    InsertionSort(arr);
    return 0;
}