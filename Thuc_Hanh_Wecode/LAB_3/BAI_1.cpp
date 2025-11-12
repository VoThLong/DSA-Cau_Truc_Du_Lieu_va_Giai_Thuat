/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
sort
stable_sort
partial_sort
set
nth_element
priority_queue
sort_heap
multiset
map
multimap
###End banned keyword*/
// ###INSERT CODE HERE -

#include <bits/stdc++.h>
using namespace std;

void quickSort(vector<string> &arr, int low, int high)
{
    if (low >= high)
        return;

    int mid = low + (high - low) / 2;
    if (arr[mid] < arr[low])
        swap(arr[low], arr[mid]);
    if (arr[high] < arr[low])
        swap(arr[low], arr[high]);
    if (arr[mid] < arr[high])
        swap(arr[mid], arr[high]);
    swap(arr[mid], arr[high]);

    string pivot = arr[high];
    int i = low;
    int j = high - 1;

    while (i <= j)
    {
        while (i <= j && arr[i] < pivot)
            i++;
        while (i <= j && pivot < arr[j])
            j--;

        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    swap(arr[i], arr[high]);

    if (low < j)
        quickSort(arr, low, j);
    if (i < high)
        quickSort(arr, i, high);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<string> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int count = 0;

    if (n > 0)
    {
        // Sắp xếp
        quickSort(arr, 0, n - 1);

        // Đếm unique
        count = 1; // Phần tử đầu tiên
        for (int i = 1; i < n; i++)
        {
            if (arr[i] != arr[i - 1])
            {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}