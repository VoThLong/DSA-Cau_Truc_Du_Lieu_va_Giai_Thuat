#include <iostream>
#include <vector>
#include <cmath> // Thư viện để sử dụng hàm abs()

using namespace std;

const double EPSILON = 1e-9; // Ngưỡng sai số nhỏ để so sánh số thực

// Định nghĩa một cấu trúc (struct) để lưu tọa độ điểm, giúp code dễ đọc hơn
struct Point {
    double x, y, z;
};

int main() {
    int n;
    cin >> n;

    // Sử dụng vector thay cho mảng động, giúp quản lý bộ nhớ dễ dàng và an toàn hơn
    vector<Point> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].x >> arr[i].y >> arr[i].z;
    }

    int m;
    cin >> m;

    vector<Point> brr(m);
    for (int i = 0; i < m; ++i) {
        cin >> brr[i].x >> brr[i].y >> brr[i].z;
    }
    cout << endl; // In xuống dòng sau khi đọc xong các điểm brr

    // Vòng lặp để kiểm tra từng điểm trong brr
    for (int i = 0; i < m; ++i) {
        bool found = false;
        int found_index = -1;
        
        // Tìm kiếm tuần tự trong danh sách arr
        for (int k = 0; k < n; ++k) {
            // So sánh 3 tọa độ với ngưỡng sai số EPSILON
            if (abs(brr[i].x - arr[k].x) < EPSILON && 
                abs(brr[i].y - arr[k].y) < EPSILON && 
                abs(brr[i].z - arr[k].z) < EPSILON) {
                found = true;
                found_index = k;
                break; // Tìm thấy rồi thì thoát khỏi vòng lặp tìm kiếm
            }
        }

        // In kết quả
        if (found) {
            cout << found_index << endl;
        } else {
            cout << "KHONG" << endl;
        }
    }

    return 0;
}