#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Tối ưu nhập xuất
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, M;
    if (!(cin >> n >> M)) return 0;

    // Mảng đếm số lượng phần tử tại mỗi bucket
    vector<int> count(M, 0);

    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;
        int idx = key % M;
        count[idx]++;
    }

    // Bước 1: Tìm số lần đụng độ lớn nhất (Max Collision)
    // Số đụng độ = (số phần tử) - 1.
    // Thực tế chỉ cần tìm ô có nhiều phần tử nhất (Max Count) là được.
    
    int maxCollision = 0;

    for (int i = 0; i < M; i++) {
        if (count[i] > 1) { // Chỉ tính khi có đụng độ
            int currentCollision = count[i] - 1;
            if (currentCollision > maxCollision) {
                maxCollision = currentCollision;
            }
        }
    }

    // Bước 2: In ra các địa chỉ đạt maxCollision
    // Chỉ in nếu có ít nhất 1 vụ đụng độ xảy ra (maxCollision > 0)
    if (maxCollision > 0) {
        for (int i = 0; i < M; i++) {
            // Tính lại số đụng độ của ô hiện tại
            int currentCollision = (count[i] > 1) ? (count[i] - 1) : 0;
            
            if (currentCollision == maxCollision) {
                cout << i << endl; // Yêu cầu đề: mỗi địa chỉ một dòng
            }
        }
    }

    return 0;
}