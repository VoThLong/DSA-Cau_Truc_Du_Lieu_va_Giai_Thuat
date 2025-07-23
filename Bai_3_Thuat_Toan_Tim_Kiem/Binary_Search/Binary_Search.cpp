#include <iostream>
#include <vector>

using namespace std;

int Binary_Search(const vector<int>& vec, int value)
{
    int left, right;
    left = 0;
    right = vec.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        //Tránh tràn số

        if (vec[mid] == value)
        {
            return mid;
        }
        else if (vec[mid] < value)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1; // Trả về -1 nếu không tìm thấy  
}


int main()
{
    //int n;
    //cin >> n;
    vector<int> arr = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91, 101, 112, 124, 136, 150};
    int i = Binary_Search(arr, 101);
    cout << "Vị trí phần tử cần tìm là: " << i << endl;

    return 0;
}