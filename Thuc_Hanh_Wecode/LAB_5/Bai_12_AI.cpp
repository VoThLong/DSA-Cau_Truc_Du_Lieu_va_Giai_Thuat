#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Tối ưu nhập xuất
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, M;
    // Kiểm tra đầu vào
    if (!(cin >> n >> M)) return 0;

    // Mảng đếm số lượng phần tử tại mỗi địa chỉ (bucket)
    // count[i] lưu số lượng khóa băm vào vị trí i
    vector<int> count(M, 0);

    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;
        int idx = key % M;
        count[idx]++;
    }

    // Bước 1: Tìm số lượng đụng độ ít nhất (nhưng phải > 0)
    // Số đụng độ = (số phần tử trong ô) - 1
    // Ta tìm min của (count[i] - 1) với điều kiện count[i] > 1
    
    int minCollision = 2000000000; // Khởi tạo số rất lớn
    bool foundAnyCollision = false;

    for (int i = 0; i < M; i++) {
        if (count[i] > 1) { // Chỉ xét các ô CÓ đụng độ
            int currentCollision = count[i] - 1;
            if (currentCollision < minCollision) {
                minCollision = currentCollision;
            }
            foundAnyCollision = true;
        }
    }

    // Bước 2: In ra các địa chỉ thỏa mãn
    if (foundAnyCollision) {
        bool first = true;
        for (int i = 0; i < M; i++) {
            // Kiểm tra: Có đụng độ VÀ số đụng độ bằng mức thấp nhất tìm được
            if (count[i] > 1 && (count[i] - 1) == minCollision) {
                if (!first) cout << " "; // In khoảng trắng giữa các số
                cout << i;
                first = false;
            }
        }
    }
    
    // Lưu ý: Nếu không có ô nào bị đụng độ, chương trình không in gì cả (đúng logic)

    return 0;
}