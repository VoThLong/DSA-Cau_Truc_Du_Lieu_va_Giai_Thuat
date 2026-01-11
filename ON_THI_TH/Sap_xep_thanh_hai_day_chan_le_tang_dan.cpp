/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/
#include <iostream>
#include <vector>

using namespace std;

void Sort(vector<int> &);

int main()
{
    int n, k;
    vector<int> nums;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        nums.push_back(k);
    }
    Sort(nums);
    for (int i = 0; i < n; i++) {
        cout << nums[i] << ' ';
    }
    return 0;
}

//###INSERT CODE HERE -

// void quicksort(vector<int> &arr, int left, int right)
// {
//     if (left >= right)
//     {
//         return;
//     }
//     int pivot = arr[ left + (right - left) / 2];
//     int i = left;
//     int j = right;
//     while (i <= j)
//     {
//         while(arr[i] < pivot)
//         {
//             i++;
//         }
//         while(arr[j] > pivot)
//         {
//             j++;
//         }
//         if (i <= j)
//         {
//             swap(arr[i], arr[j]);
//             i++;
//             j--;
//         }
//     }

//     if (left < j)
//     {
//         quicksort(arr, left, j);
//     }
//     if (right > i)
//     {
//         quicksort(arr, i, right);
//     }
// }

// void Sort(vector<int> &arr)
// {
//     vector<int> odd, even;
//     for(int i = 0; i < arr.size(); i++)
//     {
//         if(arr[i] % 2 == 1)
//         {
//             odd.push_back(arr[i]);
//         }
//         else
//         {
//             even.push_back(arr[i]);
//         }
//     }
//     if(!odd.empty())
//     quicksort(odd, 0, odd.size() - 1);
//     if(!even.empty())
//     quicksort(even, 0, even.size() - 1);
//     for (int i = 0; i < even.size(); i++)
//     {
//         arr[i] = even[i];
//     }
//     for (int i = 0; i < odd.size() - 1; i++)
//     {
//         arr[i + even.size()] = odd[i];
//     }
// }

void quicksort(vector<int> &arr, int left, int right) {
    if (left >= right) return;

    int pivot = arr[left + (right - left) / 2];
    int i = left;
    int j = right;

    while (i <= j) {
        // Thêm điều kiện i < right và j > left để tránh chạy lố
        while (i <= right && arr[i] < pivot) i++;
        while (j >= left && arr[j] > pivot) j--; // Dòng gây lỗi cũ đã được bọc bảo vệ
        
        if (i <= j) {
            // Dùng swap của thư viện hoặc tự viết đều được
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    if (left < j) quicksort(arr, left, j);
    if (right > i) quicksort(arr, i, right);
}

void Sort(vector<int> &arr) {
    vector<int> odd, even;
    
    // Tách mảng
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % 2 != 0) odd.push_back(arr[i]);
        else even.push_back(arr[i]);
    }

    // CHỈ GỌI SORT KHI CÓ ÍT NHẤT 2 PHẦN TỬ
    // Đây là chốt chặn quan trọng nhất để tránh lỗi
    if (odd.size() > 1) quicksort(odd, 0, (int)odd.size() - 1);
    if (even.size() > 1) quicksort(even, 0, (int)even.size() - 1);

    // Ghép mảng lại
    int index = 0;
    for (int i = 0; i < even.size(); i++) arr[index++] = even[i];
    for (int i = 0; i < odd.size(); i++) arr[index++] = odd[i];
}