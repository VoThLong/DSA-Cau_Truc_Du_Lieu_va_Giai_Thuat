#include <bits/stdc++.h>
using namespace std;

void input_vector(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void quick_sort(vector<int> &arr, int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int mid = low + (high - low) / 2;
    if (arr[low] > arr[mid])
    {
        swap(arr[low], arr[mid]);
    }
    if (arr[low] > arr[high])
    {
        swap(arr[low], arr[high]);
    }
    if (arr[mid] > arr[high])
    {
        swap(arr[mid], arr[high]);
    }
    swap(arr[mid], arr[high]);

    int pivot = arr[high];
    int i = low, j = high - 1;
    while (i <= j)
    {
        while (i <= j && arr[i] < pivot)
        {
            i++;
        }
        while (i <= j && arr[j] >= pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    swap(arr[i], arr[high]);
    if (low < j)
    {
        quick_sort(arr, low, j);
    }
    if (high > i + 1)
    {
        quick_sort(arr, i + 1, high);
    }
}

int find_upper_bound(vector<int> &arr, int n, int x)
{

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    input_vector(arr, n);
    vector<int> arr1(q);
    input_vector(arr1, q);
    quick_sort(arr, 0, n - 1);

    // Xử lý Q truy vấn
    for (int i = 0; i < q; i++)
    {
        int result = -1;
        
        for (int j = 0; j < n; j++)
        {
            if (arr[j] > arr1[i])
            {
                result = arr[j];
                break;
            }
        }
        
        cout << result << "\n";
    }
    return 0;
}