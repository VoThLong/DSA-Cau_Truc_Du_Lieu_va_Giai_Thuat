#include  <iostream>
#include <vector>
using namespace std;

void Quick_Sort(vector<int> &arr, int left, int right)
{
    int pivot = arr[left + (right - left) / 2];
    int i = left;
    int j = right;

    while (i <= j)
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if(i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if(left < j)
    {
        Quick_Sort(arr, left , j);
    }
    if(right > i)
    {
        Quick_Sort(arr, i , right);
    }
}

bool Binary_Search(vector<int> &arr, int val)
{
    int left = 0;
    int right = arr.size() - 1;
    while (left  <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == val)
        {
            return true;
        }
        else if (arr[mid] < val)
        {
            left = mid + 1;
        }
        else if (arr[mid] > val)
        {
            right = mid - 1;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Quick_Sort(arr, 0, arr.size() - 1);
    for (int i = 0; i < q; i++)
    {
        int temp;
        cin >> temp;
        if (Binary_Search(arr, temp)) {cout << "YES" << '\n';}
        else {cout << "NO" << '\n';}
    }
return 0;
}