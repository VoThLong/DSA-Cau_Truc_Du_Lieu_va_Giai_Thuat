#include <iostream>
#include <vector>

using namespace std;

template <class Object>
void swap(Object &a, Object &b)
{
    Object temp = a;
    a = b;
    b = temp;
}

template <class Object>
void printvector(const vector<Object> &arr)
{
    for (const auto &elem : arr)
    {
        cout << elem << " ";
    }
    cout << endl;
}

template <class Object>
void ShellSort_ShellsGap(vector<Object> &arr) 
{
    int n = (int)arr.size(); // ép kiểu từ size_t sang int
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Insertion sort trên các dãy phần tử cách nhau 'gap'
        for (int i = gap; i < n; ++i) {
            Object key = arr[i];
            int j = i;
            // Dịch các phần tử arr[j-gap], arr[j-2*gap], ... lớn hơn key sang phải
            while (j - gap >= 0 && key < arr[j - gap]) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = key;
        }
        // Demo: in mảng sau mỗi lần giảm gap
        cout << "After gap = " << gap << ": ";
        printvector(arr);
    }
}

// ======= Demo =======
int main() 
{
    vector<int> a = {8, 5, 3, 7, 6, 2, 4, 1};

    cout << "Initial: ";
    printvector(a);

    ShellSort_ShellsGap(a);

    cout << "Sorted : ";
    printvector(a);
    return 0;
}
