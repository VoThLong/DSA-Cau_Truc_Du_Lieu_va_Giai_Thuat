#include <iostream>
#include <vector>

#include <cstdio>

using namespace std;

int LinearSearch(const vector<int> &arr, int target)
{
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] == target)
        {
        return i;
        }
    }

    return -1;
}

int main()
{
    // ---- BƯỚC QUAN TRỌNG NHẤT ----
    // Điều hướng stdin để đọc từ file "input.txt"
    freopen("input1.txt", "r", stdin);
    // Điều hướng stdout để ghi vào file "output.txt"
    freopen("output1.txt", "w", stdout);

    //Nhập số  lượng các phần tử
    int n;
    cin >> n;
    vector<int> arr(n);

    // nhập các phần tử
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Nhập vào phần tử cần tìm
    int target;
    cin >> target;
    int index = LinearSearch(arr, target);
    if(index == -1)
    {
        cout << "Khong co phan tu can tim";
    }
    else
    {
        cout << "Phan tu can tim o vi tri: " << index;
    }
    return 0;
    
}