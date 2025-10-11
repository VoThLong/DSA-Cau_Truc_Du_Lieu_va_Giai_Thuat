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
void Input(vector<Object> &arr) {
    for(int i = 0; i < arr.size(); i++) {
        cin >> arr[i];
    }
}

template <class Object>
void Output(vector<Object> &arr) {
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <class Object>
void SelectionSort(vector<Object> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            Swap(arr[i], arr[minIndex]);
            Output(arr);

        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    Input(arr);
    SelectionSort(arr);
    

    return 0;
}
