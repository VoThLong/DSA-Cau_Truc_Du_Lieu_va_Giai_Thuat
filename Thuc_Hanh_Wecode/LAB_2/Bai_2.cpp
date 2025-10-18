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

struct point3D
{
    int x, y, z;
};

bool Compare(const point3D &p1, const point3D &p2)
{
     if (p1.x != p2.x) 
    {
        return p1.x < p2.x;
    }
    else if (p1.y != p2.y)
    {
        return p1.y > p2.y;
    }
    else return p1.z < p2.z;
}

void QuickSort(vector<point3D> &arr, int low, int high)
{
    if (low >= high)
    {
        return;
    }

    // Median-of-three pivot selection
    int mid = low + (high - low) / 2;
    if (Compare(arr[mid], arr[low])) swap(arr[low], arr[mid]);
    if (Compare(arr[high], arr[low])) swap(arr[low], arr[high]);
    if (Compare(arr[mid], arr[high])) swap(arr[mid], arr[high]);
    swap(arr[mid], arr[high]);
    
    point3D pivot = arr[high];
    int i = low;
    int j = high - 1;

    while (i <= j)
    {
        while (i <= j && Compare(arr[i], pivot))
        {
            i++;
        }
        while (i <= j && Compare(pivot, arr[j]))
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
    swap(arr[i], arr[high]);

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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<point3D> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i].x >> arr[i].y >> arr[i].z;
    }

    QuickSort(arr, 0, n - 1); 

    for (int i = 0; i < n; ++i)
    {
        cout << arr[i].x << " " << arr[i].y << " " << arr[i].z << "\n";
    }
    return 0;
}   