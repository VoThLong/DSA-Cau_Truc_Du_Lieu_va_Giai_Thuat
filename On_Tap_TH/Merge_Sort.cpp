#include <iostream>
#include <vector>
using namespace std;


void Merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> arrleft(n1);
    vector<int> arrright(n2);
    
    for (int i = 0; i < n1; i++)
    {
        arrleft[i] = arr[left+ i];
    }
    for (int i = 0; i < n2; i++)
    {
        arrright[i] = arr[mid + 1 + i];
    }
    
    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2)
    {
        if (arrleft[i] <= arrright[j])
        {
            arr[k] = arrleft[i];
            i++;
        }
        else
        {
            arr[k] = arrright[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = arrleft[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = arrright[j];
        j++;
        k++;
    }
    
}
void Merge_Sort(vector<int> &arr, int left, int right)
{
    if(left >= right)
    {
        return;
    }
    int mid = left + (right - left) / 2;
    Merge_Sort(arr, left, mid);
    Merge_Sort(arr, mid + 1, right);
    Merge(arr, left, mid, right);
}


int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
    Merge_Sort(arr, 0, n - 1);
    for(int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ' ';
    }
    return 0;
    
}
