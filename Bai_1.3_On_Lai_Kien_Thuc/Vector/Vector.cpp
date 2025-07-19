#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    //khai báo vector
    vector<int> a; // vector rỗng kiểu số nguyên

    //Các cách khởi tạo vector
    vector<int> vect1(10); // vector có 10 phần tử, giá trị mặc định là 0
    vector<int> vect2(10, 5); // vector có 10 phần tử, giá trị mặc định là 5
    vector<int> vect3 = {1, 2, 3, 4, 5}; // vector khởi tạo từ danh sách
    vector<int> vect4(vect3); // vector sao chép từ vect3

    //Các phuơng thức của vector
    /* Thêm/Xóa phần tử:
            push_back(x): Thêm phần tử x vào cuối vector
            pop_back(): Xóa phần tử cuối cùng
            insert(pos, x): Chèn phần tử x vào vị trí pos
            erase(pos): Xóa phần tử tại vị trí pos
            clear(): Xóa toàn bộ phần tử
        Truy cập và thông tin:
            size(): Số lượng phần tử
            empty(): Kiểm tra vector có rỗng không
            front(): Lấy phần tử đầu tiên
            back(): Lấy phần tử cuối cùng
            at(index): Truy cập phần tử tại vị trí index (an toàn)
            operator[]: Truy cập phần tử tại vị trí index (không kiểm tra giới hạn)
    */
    vect1.push_back(10); // Thêm 10 vào cuối vect
    vect1.push_back(20); // Thêm 20 vào cuối vect1
    for (int i = 0; i < vect1.size(); i++) {
        cout << vect1[i] << " "; // In ra các phần tử của vect1
    }
    cout << endl;

    vect1.pop_back(); // Xóa phần tử cuối cùng (20)
    for (int i = 0; i < vect1.size(); i++) {
        cout << vect1[i] << " "; // In ra các phần tử của vect1 sau khi xóa
    }
    cout << endl;

    //insert(pos, x) : chen phần tử x vào vị trí pos
    vect1.insert(vect1.begin() + 1, 15); // Chèn
    for (int i = 0; i < vect1.size(); i++) {
        cout << vect1[i] << " "; // In ra các phần tử của vect1 sau khi chèn
    }
    cout << endl;

    vect1.erase(vect1.begin()); // Xóa phần tử tại vị trí 1
    for (int i = 0; i < vect1.size(); i++) {
        cout << vect1[i] << " "; // In ra các phần tử của vect1 sau khi chèn
    }
    cout << endl;

    vect1.clear(); // Xóa toàn bộ phần tử
    cout << "Size of vect1 after clear: " << vect1.size() << endl;

    //nhập mảng từ bàn phím
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n); // Khởi tạo vector với n phần tử
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // Nhập từng phần tử vào vector
    }
    for (int i : arr) {
        cout << i << " "; // In ra các phần tử của vector arr
    }
    cout << endl;

    //Các thao tác với Vector
    /* 
    sắp xếp vector: std::sort(arr.begin(), arr.end());
    tìm kiếm phần tử: std::find(arr.begin(), arr.end(), value);
    sao chép vector: std::copy(arr.begin(), arr.end(), std::back_in
    tim giá trị max:  std::max_element(arr.begin(), arr.end());
    tim giá trị min:  std::min_element(arr.begin(), arr.end());
    đảo ngược vector: std::reverse(arr.begin(), arr.end());
    nối hai vector: std::vector<int> result = arr1;
    */
   

    return 0;
    
}