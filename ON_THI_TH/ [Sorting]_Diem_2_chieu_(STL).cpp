#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point
{
    int x, y;
};

bool ComparePoint(const Point &P1, const Point &P2)
{
    if (P1.x != P2.x)
        {return (P1.x <= P2.x);}
    else
        {return (P1.y > P2.y);}
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

    sort(arr.begin(), arr.end(),ComparePoint);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i].x << ' ' << arr[i].y << '\n';
    }

    return 0;
}