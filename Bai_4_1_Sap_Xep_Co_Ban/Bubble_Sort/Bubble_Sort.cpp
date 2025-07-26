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
void BubbleSort(vector<Object> &arr)
{
    size_t n = arr.size();
    for (size_t i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (size_t j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                Swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) 
        {
            break; // If no two elements were swapped, the array is sorted
        }
    }
}

int main()
{
    vector<int> arr = {4, 2, 1, 3};
    BubbleSort(arr);
    cout << "Sorted array: \n";
    for (const auto& element : arr) {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}


/*
4 2 1 3
2 4 1 3
2 1 4 3
2 1 3 4
1 2 3 4
end
*/