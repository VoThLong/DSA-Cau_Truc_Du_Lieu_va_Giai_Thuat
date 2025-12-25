/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/
#include <iostream>
#include <string>

#define LOAD 0.7
#define EMPTY 0
#define DELETE -1
using namespace std;

struct Hocsinh {
    int Maso;
    string Hoten;
    int Namsinh;
    bool Gioitinh;
    double TBK;
};

struct Hashtable {
    int M; // Kich thuoc bang bam
    int n; // so phan tu trong bang bam
    Hocsinh *table;
};

void CreateHashtable(Hashtable &, int);
int Delete(Hashtable &, int, int &);
void PrintHashtable(Hashtable);
void DeleteHashtable(Hashtable &);

void Input(Hocsinh &x) {
    cin >> x.Maso;
    getline(cin>>ws, x.Hoten);
    cin >> x.Gioitinh;
    cin >> x.Namsinh;
    cin >> x.TBK;
}
int main()
{
    Hashtable hashtable;

    int m, n, k, nprob;
    Hocsinh hs;

    cin >> m;
    CreateHashtable(hashtable, m);
    for (int i = 0; i < m; i++) {
        Input(hs);
        hashtable.table[i] = hs;
        if (hs.Maso > 0)
            hashtable.n++;
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        if (Delete(hashtable, k, nprob)) {
            cout << "THAM DO " << nprob << endl;
        }
        else {
            cout << "KHONG XOA DUOC" << endl;
        }
    }
    PrintHashtable(hashtable);
    DeleteHashtable(hashtable);
    return 0;
}

void CreateHashtable(Hashtable &ht, int m) {
    ht.table = new Hocsinh[m];
    if (ht.table == NULL)
        exit(1);
    for (int i = 0; i < m; i++) {
        ht.table[i].Maso = EMPTY;
    }
    ht.M = m;
    ht.n = 0;
}

void PrintHashtable(Hashtable ht) {
    for (int i = 0; i < ht.M; i ++) {
        Hocsinh hs = ht.table[i];
        if (hs.Maso > 0)
            cout << '[' << hs.Maso << ",  " << hs.Hoten << "  , " << hs.Gioitinh << ", " << hs.Namsinh << ", " << hs.TBK << "]\n";
        else
            cout << "[" << hs.Maso <<  ",  " << "  , " << ", " << ", " << "]\n";
    }
}

void DeleteHashtable(Hashtable &ht) {
    delete [] ht.table;
    ht.table = NULL;
    ht.M = 0;
}

int Delete(Hashtable &ht, int maso, int &nprob) {


nprob = -1; // Khởi tạo số lần thăm dò
    int M = ht.M;
    
    // Duyệt qua bảng băm (giới hạn tối đa M lần để tránh lặp vô tận)
    for (int i = 0; i < M; i++) {
        nprob++; // Tăng số lần thăm dò ở mỗi bước lặp
        
        // Công thức thăm dò bậc hai: h(key, i) = ((key % M) + i*i) % M
        // Lưu ý: i*i có thể lớn nên ép kiểu long long nếu cần, 
        // nhưng với bài tập cơ bản int thường đủ.
        int idx = ((maso % M) + i * i) % M;

        // Trường hợp 1: Gặp ô trống (EMPTY) -> Phần tử không tồn tại
        if (ht.table[idx].Maso == EMPTY) {
            return 0;
        }

        // Trường hợp 2: Tìm thấy phần tử cần xóa
        if (ht.table[idx].Maso == maso) {
            ht.table[idx].Maso = DELETE; // Đánh dấu là đã xóa (-1)
            ht.n--; // Giảm số lượng phần tử
            return 1; // Trả về thành công
        }

        // Trường hợp 3: Gặp phần tử khác hoặc gặp vết tích đã xóa (DELETE)
        // -> Tiếp tục vòng lặp (i tăng lên) để thăm dò vị trí tiếp theo
    }

    return 0; // Không tìm thấy sau khi đã thăm dò hết giới hạn

}