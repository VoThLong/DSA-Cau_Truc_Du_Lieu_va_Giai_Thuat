#include <iostream>
#include <vector>

using namespace std;

int Interpolation_Search(vector<int> arr, int value)
{
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right && value >= arr[left] && value <= arr[right])
    {
        if (left == right)
        {
            return (arr[left] == value) ? left : -1;
        }
        int pos = left + ((double)(right - left) / (arr[right] - arr[left]) * (value - arr[left]));
        if (arr[pos] == value)
        {
            return pos;
        }
        if (arr[pos] < value)
        {
            left = pos + 1;
        }
        else
        {
            right = pos - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int value = 70;
    int index = Interpolation_Search(arr, value);
    if (index != -1)
    {
        cout << "Element found at index: " << index << endl;
    }
    else
    {
        cout << "Element not found in the array." << endl;
    }
    return 0;
}