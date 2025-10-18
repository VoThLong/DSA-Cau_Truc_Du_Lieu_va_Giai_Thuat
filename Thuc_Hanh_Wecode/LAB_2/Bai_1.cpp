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
//###INSERT CODE HERE -

#include <iostream>
#include <vector>
using namespace std;

struct point2D
{
    int x, y;
};

// bool Compare(const point2D &p1, const point2D &p2)
// {
//      if (p1.x != p2.x) 
//     {
//         return p1.x < p2.x;
//     }
//     return p1.y > p2.y;
// }

void QuickSort(vector<point2D> &arr, int low, int high)
{
    if (low >= high)
    {
        return;
    }

    point2D pivot = arr[low + (high - low) / 2];
    int i = low;
    int j = high;

    while (i <= j)
    {
        while (arr[i].x < pivot.x || (arr[i].x == pivot.x && arr[i].y > pivot.y))
        {
            i++;
        }
        while (arr[j].x > pivot.x || (arr[j].x == pivot.x && arr[j].y < pivot.y))
        {
            j--;
        }
        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (low < j)
    {
        QuickSort(arr, low, j);
    }
    if (i < high)
    {
        QuickSort(arr, i, high);
    }

}

int main()
{
    int n;
    cin >> n;
    vector<point2D> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i].x >> arr[i].y;
    }

    QuickSort(arr, 0, n - 1);

    for (int i = 0; i < n; ++i)
    {
        cout << arr[i].x << " " << arr[i].y << endl;
    }
    return 0;
}