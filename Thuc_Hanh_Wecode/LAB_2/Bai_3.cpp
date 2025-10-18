#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void PrintVector(const vector<int> &arr, int left, int right)
{
    if (left == 0)
    {
        cout << "[ ";
        for (int i = left; i <= right; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "] ";
        for (int i = right + 1; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
    }
    else
    {
        for (int i = 0; i < left; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "[ ";
        for (int i = left; i <= right; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "] ";
        for (int i = right + 1; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
    }
}

template <class T> //trộn 2 mảng đã sắp xếp
void MergeRange(vector<T> &arr, int left, int mid, int right)
{
    vector<T> Merged(right - left + 1); //tạo mảng tạm để chứa mảng đã sắp xếp

    for (int i = left; i <= right; i++) //sao chép dữ liệu vào mảng tạm để tránh mất dữ liệu
    {
        Merged[i - left] = arr[i];
    }

    int Size_Merge = Merged.size(); //chuyển đổi index
    int mid_in_merge = mid - left;
    int i = 0, j = mid_in_merge + 1; //i là con trỏ nửa trái, j là con trỏ nửa phải
    int dst = left; //dst là con trỏ mảng gốc

    while (i <= mid_in_merge && j < Size_Merge)
    {
        if (Merged[i] < Merged[j])
        {
            arr[dst++] = Merged[i++];
        }
        else
        {
            arr[dst++] = Merged[j++];
        }
    }

    // Sao chép phần còn lại (nếu có) vào mảng gốc
    while (i <= mid_in_merge)
    {
        arr[dst++] = Merged[i++];
    }
    while (j < Size_Merge)
    {
        arr[dst++] = Merged[j++];
    }
}

template <class T> //chia + đê quy: phần log(n) - chia đôi đến khi còn một phần tử
void MergeSort_td(vector<T> &arr, int left, int right, bool Log = false)
{
    if (left >= right) return;

    int mid = (right +  left) / 2; //Điều kiện dừng
    MergeSort_td(arr, left, mid, Log);
    MergeSort_td(arr, mid + 1, right, Log);
    MergeRange(arr, left, mid, right);
    
    if (Log)
    {
        PrintVector(arr, left, right);
        cout << "\n";
    }
}

template <class T> //hàm gọi cho tiện
void MergeSort(vector<T> &arr, bool Log = false)
{
    if (arr.empty()) return;
    MergeSort_td(arr, 0, arr.size() - 1, Log);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    MergeSort(arr, true);   

    return 0;
}