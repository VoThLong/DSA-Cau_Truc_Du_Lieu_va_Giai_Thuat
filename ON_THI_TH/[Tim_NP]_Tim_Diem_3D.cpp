#include <iostream>
#include <vector>
using namespace std;

struct Point3D
{
    double x, y, z;
};

int Compare(const Point3D &p1, const Point3D &p2)
{
    // So sánh X
    if (p1.x != p2.x) 
        return (p1.x < p2.x) ? -1 : 1;
    
    // Nếu X bằng nhau thì so sánh Y
    if (p1.y != p2.y) 
        return (p1.y < p2.y) ? -1 : 1;
        
    // Nếu Y bằng nhau thì so sánh Z
    if (p1.z != p2.z) 
        return (p1.z < p2.z) ? -1 : 1;

    // Nếu cả 3 bằng nhau
    return 0;
}

int Binary_Search(const vector<Point3D> &arr, Point3D &target)
{
    int count = 0;
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        count++;
        int  res = Compare(arr[mid], target);
        if(res == 0) {return count;}
        if (res == -1)
        {
            left = mid + 1;
        }
        if (res == 1)
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    vector<Point3D> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].x >> arr[i].y >> arr[i].z;
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        Point3D temp;
        cin >> temp.x >> temp.y >> temp.z;
        int z = Binary_Search(arr, temp);
        if (z == -1) {cout << "KHONG\n";}
        else {cout << z << '\n';}
    }
    return 0;
}