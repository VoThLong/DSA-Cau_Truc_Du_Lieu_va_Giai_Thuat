#include <iostream>
#include <vector>

using namespace std;

int Ordered_Linear_Search(const vector<int> &arr, int target)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == target)
        {
            return i; // Return the index if found
        }
        // Since the array is ordered, if current element is greater than target,
        // the target cannot be found in the remaining elements
        if (arr[i] > target)
        {
            return -1; // Target not found
        }
    }
    return -1; // Target not found
}

int main()
{
    // ---- BƯỚC QUAN TRỌNG NHẤT ----
    // Điều hướng stdin để đọc từ file "input.txt"
    freopen("input.txt", "r", stdin);
    // Điều hướng stdout để ghi vào file "output.txt"
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> arr(n);
    // Nhập các phần tử
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // Nhập vào phần tử cần tìm
    int target;
    cin >> target;
    int index = Ordered_Linear_Search(arr, target);
    if (index == -1)
    {
        cout << "Khong co phan tu can tim";
    }
    else
    {
        cout << "Phan tu can tim o vi tri: " << index;
    }
    return 0;
}