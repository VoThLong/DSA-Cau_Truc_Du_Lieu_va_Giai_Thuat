#include <iostream>
#include <algorithm>
#include <vector> // Nên dùng vector thay cho mảng động

struct Point 
{
    int x, y;
};

bool comparePoints(const Point &p1, const Point &p2) 
{
    if (p1.x != p2.x) 
    {
        return p1.x < p2.x;
    }
    return p1.y > p2.y;
}

int main() 
{
    // Thêm 2 dòng này để tăng tốc độ I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    // Sử dụng std::vector để quản lý bộ nhớ an toàn hơn và hiệu quả hơn
    std::vector<Point> points(n); 
    for (int i = 0; i < n; ++i) 
    {
        std::cin >> points[i].x >> points[i].y;
    }

    std::sort(points.begin(), points.end(), comparePoints);

    for (int i = 0; i < n; ++i) 
    {
        std::cout << points[i].x << " " << points[i].y << "\n";
    }

    return 0;
}