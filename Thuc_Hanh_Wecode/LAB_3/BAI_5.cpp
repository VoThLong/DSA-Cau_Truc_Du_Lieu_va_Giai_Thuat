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

int find_lower_bound(vector<int> &arr, int n, int x)
{
    int left = 0;
    int right = n - 1;
    int ans = -1; // Lưu kết quả, mặc định là -1

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] >= x)
        {
            // arr[mid] là một ứng cử viên.
            // Đây có thể là câu trả lời, ta lưu lại
            ans = arr[mid];
            // Và thử tìm xem có số nào nhỏ hơn (ở bên trái)
            // mà vẫn còn lớn hơn x không.
            right = mid - 1;
        }
        else // (arr[mid] <= x)
        {
            // arr[mid] không phải là câu trả lời (vì nó <= x).
            // Mọi phần tử bên trái nó cũng vậy.
            // Tìm ở bên phải.
            left = mid + 1;
        }
    }

    return ans;
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

    for (int i = 0; i < q; i++)
    {
        int result = find_lower_bound(arr, n, arr1[i]);
        cout << result << "\n";
    }
    return 0;
}