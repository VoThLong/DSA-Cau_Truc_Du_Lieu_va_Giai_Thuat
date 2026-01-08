#include <iostream>
#include "HashTable.h"

using namespace std;

int main() {
    // 1. Tạo bảng băm size 7
    cout << "--- KHOI TAO BANG BAM (SIZE 7) ---" << endl;
    HashTable ht(7);

    // 2. Thêm dữ liệu (Test đụng độ: 15%7=1, 8%7=1, 22%7=1)
    int data[] = {15, 11, 27, 8, 12, 22};
    int n = sizeof(data)/sizeof(data[0]);

    for (int i = 0; i < n; i++) {
        ht.insertItem(data[i]);
    }

    // 3. Hiển thị
    cout << "\n--- BANG BAM LUC DAU ---" << endl;
    ht.displayHash();

    // 4. Test xóa
    cout << "\n--- XOA SO 8 (Gay dung do o Bucket 1) ---" << endl;
    ht.deleteItem(8);
    ht.displayHash();

    return 0;
}