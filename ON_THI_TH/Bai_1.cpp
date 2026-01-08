#include <iostream>
#include <vector>
using namespace std;

struct Point
{
    int x, y;
};

bool comparePoint(Point &p1, Point &p2)
{
    if (p1.x != p2.x)
    {
        return p1.x < p2.x;
    }
    return p1.y > p2.y;
}
void SwapPoint (Point &p1, Point &p2)
{
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}



int main ()
{
    int n;
    cin >> n;
    vector<Point> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].x >> arr[i].y;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; i++)
        {
            if(!comparePoint(arr[i], arr[j])) 
            {
                SwapPoint(arr[i], arr[j]);
            }
        }
    }
        for (int i = 0; i < n; ++i) 
    {
        cout << arr[i].x << " " << arr[i].y << "\n";
    }

}