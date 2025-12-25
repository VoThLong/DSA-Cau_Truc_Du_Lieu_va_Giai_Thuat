#include <iostream>
#include <vector>

using namespace std;

// Quy định giá trị biểu thị ô trống
const int EMPTY = -1;

int main() {
    // Tối ưu nhập xuất
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M, n;
    // Kiểm tra đầu vào hợp lệ
    if (!(cin >> M >> n)) return 0;

    // Khởi tạo bảng băm kích thước M, tất cả là EMPTY (-1)
    vector<int> table(M, EMPTY);
    
    long long totalCollisions = 0; // Biến lưu tổng số đụng độ

    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;

        // Tính chỉ số băm ban đầu
        int index = key % M;
        
        // Thăm dò tuyến tính
        // Lặp trong khi vị trí hiện tại ĐÃ CÓ NGƯỜI (Khác EMPTY)
        while (table[index] != EMPTY) {
            // Gặp ô đã đầy -> Xảy ra đụng độ
            totalCollisions++;
            
            // Nhảy sang ô kế tiếp (Linear Probing)
            index = (index + 1) % M;
        }

        // Sau khi vòng while kết thúc, nghĩa là table[index] đang EMPTY
        // Ta điền giá trị vào ô trống này
        table[index] = key;
    }

    // Xuất kết quả
    cout << totalCollisions << endl;

    return 0;
}