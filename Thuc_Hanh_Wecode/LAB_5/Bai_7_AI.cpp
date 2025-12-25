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
int Insert(Hashtable &, Hocsinh);
void PrintHashtable(Hashtable);
void DeleteHashtable(Hashtable &);

void Input(Hocsinh &x) {
    cin >> x.Maso;
    getline(cin>>ws, x.Hoten);
    cin >> x.Namsinh;
    cin >> x.Gioitinh;
    cin >> x.TBK;
}
int main()
{
    Hashtable hashtable;

    int m, n;
    Hocsinh hs;

    cin >> m;
    CreateHashtable(hashtable, m);
    cin >> n;
    for (int i = 0; i < n; i++) {
        Input(hs);
        Insert(hashtable, hs);
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

int Insert(Hashtable &ht, Hocsinh x) {

    // 1. Kiểm tra hệ số tải (Load Factor)
    // Nếu thêm phần tử mới mà vượt quá 0.7 kích thước bảng thì không thêm 
    if ((double)(ht.n + 1) / ht.M > LOAD) {
        return 0;
    }

    int m = ht.M;
    int key = x.Maso;

    // 2. Duyệt qua bảng băm để tìm vị trí trống (Thăm dò tuyến tính)
    for (int i = 0; i < m; i++) {
        // Áp dụng công thức băm lại: h(key, i) = ((key % M) + i) % M 
        int idx = ((key % m) + i) % m;

        // 3. Kiểm tra vị trí tìm được
        // Nếu vị trí là EMPTY (0) hoặc DELETE (-1) thì có thể chèn 
        if (ht.table[idx].Maso == EMPTY || ht.table[idx].Maso == DELETE) {
            ht.table[idx] = x; // Gán dữ liệu học sinh vào bảng [cite: 3, 5]
            ht.n++;            // Tăng số lượng phần tử hiện có [cite: 4]
            return 1;          // Trả về 1 (Thành công)
        }
    }

    // Trường hợp bảng đầy hoặc không tìm được chỗ (dù xác suất thấp do đã check load)
    return 0;
}