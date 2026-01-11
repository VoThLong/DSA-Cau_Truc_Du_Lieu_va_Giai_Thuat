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
using  namespace std;

struct Point
{
    int x, y;
};

void  SwapPoint(Point &p1, Point &p2)
{
    Point temp;
    temp.x = p1.x;
    temp.y = p1.y;

    p1.x = p2.x;
    p1.y = p2.y;
    
    p2.x = temp.x;
    p2.y = temp.y;
}

bool ComparePoint(const Point &P1, const Point &P2)
{
    if (P1.x != P2.x)
        {return (P1.x < P2.x);}
    else
        {return (P1.y > P2.y);}
}

void Selection_Sort(vector<Point> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for(int j = i + 1; j < n; j++)
        {
            if (!ComparePoint(arr[i], arr[j]))
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            swap(arr[i], arr[minIndex]);
        }
    }
}

void Quick_Sort(vector <Point> &arr, int left, int right)
{
    //Điều kiện dừng đệ quy 
    if (left > right)
    {
        return;
    }
    Point pivot = arr[left + (right - left) / 2];
    int i = left;
    int j = right;

    //So sánh và hoán đổi 
    while (i <= j)
    {
        while(ComparePoint(arr[i], pivot))
        {
            i++;
        }
        while(ComparePoint(pivot, arr[j]))
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

    //Gọi đệ quy 
    if (left < j)
    {
        Quick_Sort(arr, left, j);
    }
    if (right > i)
    {
        Quick_Sort(arr, i, right);
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<Point> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].x >> arr[i].y;
    }

    Quick_Sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i].x << ' ' << arr[i].y << '\n';
    }

    return 0;
}