#include <iostream>
#include <vector>

using namespace std;

template <class Object>
void Swap(Object &a, Object &b) {
    Object temp = a;
    a = b;
    b = temp;
}
template <class Object>
void InterchangeSort(vector<Object> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                Swap(arr[i], arr[j]);
            }
        }
    }
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};
    InterchangeSort(arr);

    cout << "Sorted array: \n";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
