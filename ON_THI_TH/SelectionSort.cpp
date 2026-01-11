#include <iostream>
#include <vector>
using namespace std;

void PrintVector (const vector<int> &arr, int left, int right)
{
    if (left == 0)
    {
        cout << "[ ";
        for (int i = left; i <= right; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "] ";
        for (int i = right + 1; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
    }
    else
    {
        for (int i = 0; i < left; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "[ ";
        for (int i = left; i <= right; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "] ";
        for (int i = right + 1; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
    }
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

    for (int i = 0; i < n; i++)
    {
        int MinI = i;
        for (int j = i + 1; j < n; j++)
        {
            if(arr[MinI] > arr[j])
            {
                MinI = j;
            }
        }
        if(MinI != i)
        {
            swap(arr[i], arr[MinI]);
            PrintVector(arr);
        }
    }

    return 0;
}
