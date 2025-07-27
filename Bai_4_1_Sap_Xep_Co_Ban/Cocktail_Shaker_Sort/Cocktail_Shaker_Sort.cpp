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
void cocktailShakerSort(vector<Object> &arr)
{
    size_t n = arr.size();
    size_t left = 0;
    size_t right = n - 1;
    size_t k = n - 1;

    while (left < right)
    {
        // Quét từ trái sang phải
        for (size_t i = left; i < right; i++)  // Sửa: i < right thay vì i < right - 1
        {
            if (arr[i] > arr[i + 1])
            {
                Swap(arr[i], arr[i + 1]);  // Sửa: swap đúng vị trí
                k = i;
            }
        }
        right = k;  // Cập nhật biên phải

        if (left >= right) break;  // Kiểm tra điều kiện dừng

        // Quét từ phải sang trái
        for (size_t i = right; i > left; i--)  // Sửa: i > left thay vì i > left + 1
        {
            if (arr[i] < arr[i - 1])
            {
                Swap(arr[i], arr[i - 1]);  // Sửa: swap đúng vị trí
                k = i;
            }
        }
        left = k;  // Cập nhật biên trái
    }
}

int main ()
{
    vector<int> arr = {1,5,6,9,7,2,3,4,8};
    cocktailShakerSort(arr);
    coutvector(arr);
    return 0;
}