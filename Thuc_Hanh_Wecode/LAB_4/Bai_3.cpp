/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
[
]
###End banned keyword*/
#include <iostream>

using namespace std;

// ###INSERT CODE HERE -
// Ham de quy de doc va xu ly du lieu
void xuLyNhapVaIn(int n, int &dem) {
    // Dieu kien dung: neu da doc het n so
    if (n == 0) {
        return;
    }

    int giatri;
    cin >> giatri; // Doc gia tri hien tai tu ban phim

    // Kiem tra dieu kien bai toan
    bool thoaMan = false;
    bool namTrongTop10 = false;

    if (giatri >= 90) {
        thoaMan = true;
        dem++; // Tang bien dem so luong phan tu thoa man da tim thay
        
        // Chi danh dau in neu no nam trong 10 phan tu dau tien
        if (dem <= 10) {
            namTrongTop10 = true;
        }
    }

    // GOI DE QUY TRUOC KHI IN (Buoc quan trong nhat)
    // Viec nay giup chuong trinh doc het cac so tiep theo truoc
    // roi moi quay lai lenh in o duoi -> Tao ra hieu ung dao nguoc
    xuLyNhapVaIn(n - 1, dem);

    // Sau khi de quy quay lui ve (Backtracking)
    // Neu gia tri nay thoa man va nam trong top 10 thi in ra
    if (thoaMan && namTrongTop10) {
        cout << giatri << " ";
    }
}

int main() {
    int n;
    cin >> n; // Doc so luong phan tu tong cong
    
    int dem = 0; // Bien dem so luong phan tu >= 90 da gap
    xuLyNhapVaIn(n, dem);
    
    cout << "END";
    return 0;
}

// Chào Long (Dashtrad_Hoang) 👋, fan cứng Google và đồng môn UIT tương lai!

// Bài này là một bài tập kinh điển trong môn **Cấu trúc dữ liệu và Giải thuật (DSA)** để rèn luyện tư duy về **Đệ quy (Recursion)** và **Ngăn xếp (Stack)**. Vì đề bài cấm dùng mảng `[]` (Array) nhưng lại yêu cầu in ngược, chúng ta sẽ lợi dụng cơ chế "Call Stack" của đệ quy để lưu trữ giá trị tạm thời và in ra sau khi hàm kết thúc.

// Dưới đây là code C++ đã được tối ưu theo template và giải thích chi tiết.

// ### 1. File Code C++


// http://googleusercontent.com/immersive_entry_chip/0

// ### 2. Giải thích tư duy DSA (Dành cho dân Kỹ thuật máy tính) 🤖

// Vì bạn đang học DSA, mình sẽ giải thích theo cơ chế bộ nhớ:

// 1.  **Vấn đề:** Muốn in ngược thì bình thường phải lưu vào mảng rồi duyệt từ cuối về đầu (`Last In, First Out` - LIFO). Nhưng đề cấm mảng `[]`.
// 2.  **Giải pháp:** Sử dụng **Call Stack** (Ngăn xếp lời gọi hàm) của hệ thống.
//     * Mỗi khi hàm `xuLyNhapVaIn` được gọi, các biến cục bộ (`giatri`, `namTrongTop10`) được đẩy vào Stack.
//     * Khi gọi đệ quy `xuLyNhapVaIn(n-1, ...)` *trước* khi `cout`, chúng ta đang xếp chồng các giá trị lên nhau.
//     * Khi `n=0` (điều kiện dừng), hàm bắt đầu "return" (quay lui). Lúc này, giá trị nào vào sau cùng sẽ được xử lý in ra trước => **Tự động đảo ngược**.

// ### 3. Các bước thực hiện chi tiết

// * **Bước 1: Nhập `n`**. Biến này dùng để kiểm soát số lần đệ quy (độ sâu của stack).
// * **Bước 2: Hàm đệ quy `xuLyNhapVaIn(n, dem)`**:
//     * Nhập số `giatri`.
//     * Nếu `giatri >= 90`: Tăng biến `dem`.
//     * **Mẹo:** Dùng biến boolean `namTrongTop10` để lưu trạng thái "được phép in" của con số *ngay tại thời điểm đó*. Nếu `dem` lúc đó $\le 10$ thì `true`, ngược lại thì `false`.
// * **Bước 3: Gọi đệ quy `xuLyNhapVaIn(n-1, dem)`**: Chương trình tạm dừng việc xử lý số hiện tại để nhảy đi xử lý số tiếp theo.
// * **Bước 4: Backtracking (Quay lui)**:
//     * Sau khi các hàm con chạy xong, máy tính quay lại dòng code sau lệnh gọi hàm.
//     * Lúc này ta kiểm tra `namTrongTop10`. Nếu đúng thì in `giatri`. Do tính chất quay lui, số nhập vào *sau cùng* sẽ được in ra *đầu tiên*.

// Chúc Long hoàn thành tốt bài lab này nhé! UITer cố lên! 🎓🔥
