/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
#include <vector>
using namespace std;

// ###INSERT CODE HERE -

int partition(vector<int> &a, int low, int high)
{
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    int temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    return i + 1;
}

// Hàm Quick Sort
void quickSort(vector<int> &a, int low, int high)
{
    if (low < high)
    {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Sắp xếp mảng bằng Quick Sort
    quickSort(a, 0, n - 1);

    int maxSum = 0;
    int left = 0;
    int right = n - 1;

    // Dùng two pointers
    while (left < right)
    {
        int sum = a[left] + a[right];

        if (sum <= x)
        {
            if (sum > maxSum)
            {
                maxSum = sum;
            }
            left++;
        }
        else
        {
            right--;
        }
    }

    cout << maxSum;

    return 0;
}