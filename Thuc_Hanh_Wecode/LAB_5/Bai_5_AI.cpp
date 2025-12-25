#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Hằng số để đánh dấu ô trống trong bảng băm
const int EMPTY = -1;

int main() {
    // Tối ưu nhập xuất dữ liệu
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, M;
    if (!(cin >> n >> M)) return 0;

    // Bảng băm khởi tạo giá trị EMPTY
    vector<int> hashTable(M, EMPTY);
    
    // Mảng đếm số lần đụng độ tại mỗi địa chỉ index
    vector<int> collisionCount(M, 0);

    for (int i = 0; i < n; ++i) {
        int key;
        cin >> key;

        // Tính chỉ số băm ban đầu
        int index = key % M;
        
        // Thăm dò tuyến tính (Linear Probing)
        // Lặp cho đến khi tìm được ô trống
        while (hashTable[index] != EMPTY) {
            // Nếu vị trí này đã có người, tức là xảy ra đụng độ TẠI VỊ TRÍ NÀY
            collisionCount[index]++;
            
            // Di chuyển đến vị trí tiếp theo (xoay vòng nếu hết bảng)
            index = (index + 1) % M;
        }

        // Tìm được ô trống thì điền giá trị vào
        hashTable[index] = key;
    }

    // Bước 1: Tìm số lần đụng độ lớn nhất (max collision)
    int maxCollision = 0;
    for (int val : collisionCount) {
        if (val > maxCollision) {
            maxCollision = val;
        }
    }

    // Bước 2: In ra tất cả các chỉ mục (index) có số đụng độ bằng maxCollision
    // Lưu ý: Đề yêu cầu in theo thứ tự từ nhỏ đến lớn -> Vòng lặp for xuôi đã đảm bảo điều này.
    bool first = true;
    for (int i = 0; i < M; ++i) {
        if (collisionCount[i] == maxCollision) {
            if (!first) cout << " ";
            cout << i;
            first = false;
        }
    }
    
    // Xuống dòng cuối cùng cho đẹp
    cout << endl;

    return 0;
}