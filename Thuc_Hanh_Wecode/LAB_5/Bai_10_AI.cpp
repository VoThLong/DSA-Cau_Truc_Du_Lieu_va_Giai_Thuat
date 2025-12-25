#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Tối ưu tốc độ nhập xuất
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N;
    float LOAD;
    
    // Nhập M, LOAD, N
    if (!(cin >> M >> LOAD >> N)) return 0;

    // Bảng băm nối kết: Mảng chứa các vector (tương đương danh sách liên kết)
    vector<vector<int>> hashTable(M);
    int currentSize = 0; // Đếm số phần tử hiện có trong bảng

    // 1. Xử lý phần thêm khóa
    for (int i = 0; i < N; i++) {
        int key;
        cin >> key;

        // KIỂM TRA HỆ SỐ TẢI TRƯỚC KHI THÊM
        // Điều kiện: (currentSize + 1) / M <= LOAD
        // Chuyển vế để dùng phép nhân tránh sai số chia: (currentSize + 1) <= M * LOAD
        if ((double)(currentSize + 1) / M > LOAD) {
            continue; // Nếu thêm vào mà vượt ngưỡng thì bỏ qua khóa này
        }

        // Nếu thoả điều kiện -> Thêm vào bảng
        int idx = key % M;
        hashTable[idx].push_back(key); // Chèn vào CUỐI danh sách (Tail Insertion)
        currentSize++;
    }

    // 2. Xử lý phần tìm kiếm
    int N_prime; // Số lượng khóa cần tìm
    cin >> N_prime;
    
    for (int i = 0; i < N_prime; i++) {
        int keyToFind;
        cin >> keyToFind;

        int idx = keyToFind % M;
        int comparisons = 0;
        bool found = false;

        // Duyệt danh sách tại vị trí idx để tìm
        for (int val : hashTable[idx]) {
            comparisons++; // Mỗi lần so sánh tính là 1 bước
            if (val == keyToFind) {
                cout << comparisons << endl; // Tìm thấy -> In số lần so sánh
                found = true;
                break; // Dừng tìm kiếm
            }
        }

        // Nếu duyệt hết danh sách mà không thấy
        if (!found) {
            cout << "KHONG" << endl;
        }
    }

    return 0;
}