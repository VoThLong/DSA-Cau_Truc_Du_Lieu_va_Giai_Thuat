#include <iostream>
#include <vector>
using namespace std;

void PrintVector(const vector<int> &arr, int &left, int &right)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (i == left) {cout << "[ ";}
        cout << arr[i] << ' ';
        if(i == right) {cout << "] ";}
    }
    cout << '\n';
}

void Merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> arr1(n1);
    vector<int> arr2(n2);

    //chia ra 2 mang con
    for(int i = 0; i < n1; i++)
    {
        arr1[i] = arr[left + i];
    }
    for(int i = 0; i < n2; i++)
    {
        arr2[i] = arr[mid + 1 + i];
    }

    //tron lai theo thu tu
    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2)
    {
        if (arr1[i] <= arr2[j])
        {
            arr[k] = arr1[i];
            i++;
        }
        else
        {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = arr1[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        arr[k] = arr2[j];
        k++;
        j++;
    }

}

void MergeSort(vector<int> &arr, int left, int right)
{
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    MergeSort(arr, left, mid);
    MergeSort(arr, mid + 1,  right);
    Merge(arr, left, mid, right);
    PrintVector(arr, left, right);
}


int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    MergeSort(arr, 0, arr.size() - 1);

}