#include <iostream>
#include <vector>

using namespace std;

int Recursive_Binary_Search(vector<int> &arr, int Left, int Right, int Value)
{
    if (Left  > Right)
    {
        return -1;
    }

    int mid = Left + (Right - Left) / 2;

    if(arr[mid] == Value)
    {
        return mid;
    }

    else if (arr[mid] < Value)
        return Recursive_Binary_Search(arr, mid + 1, Right, Value);
    else
        return Recursive_Binary_Search(arr, Left, mid - 1, Value);
}

int main()
{
    //int n;
    //cin >> n;
    vector<int> arr = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91, 101, 112, 124, 136, 150};
    int i = Recursive_Binary_Search(arr, 0, arr.size() - 1, 101);
    cout << "Vị trí phần tử cần tìm là: " << i << endl;

    return 0;
}