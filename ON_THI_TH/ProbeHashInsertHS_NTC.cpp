/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>


#define MAX 10000
#define EMPTY 0
#define NIL 0
#define DELETED -1

using namespace std;

struct Hocsinh {
    int MSHS;
    string HoTen;
    int Namsinh;
    char Gioitinh;
    double Toan, Ly, Hoa, Anh;
};


struct Hashtable {
    int M; // Kich thuoc bang bam
    int n; // so phan tu trong bang bam
    Hocsinh table[MAX];
};

void InputElement(Hocsinh &x) {
    cin >> x.MSHS; 
    getline(cin>>ws, x.HoTen);
    cin >> x.Namsinh; 
    cin >> x.Gioitinh; 
    cin >> x.Toan; 
    cin >> x.Ly; 
    cin >> x.Hoa; 
    cin >> x.Anh; 
}

void OutputElement(Hocsinh x) {
    cout << x.MSHS << endl << x.HoTen << endl << x.Namsinh << endl << x.Gioitinh << endl
            << x.Toan << endl << x.Ly << endl << x.Hoa << endl << x.Anh << endl;
}

void CreateHashtable(Hashtable &, int, Hocsinh[], int);

int main()
{
    Hashtable ht;
    Hocsinh ds[MAX];
    int m, n;

    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        InputElement(ds[i]);
    }

    CreateHashtable(ht, m, ds, n);

    cout << ht.M << ' ' << ht.n << endl;
    for (int i = 0; i < ht.M; i++) {
        OutputElement(ht.table[i]);
    }

    return 0;
}

//###INSERT CODE HERE -



void CreateHashtable(Hashtable &ht, int m, Hocsinh ds[], int n) {
    // 1. KHOI TAO BANG BAM
    ht.M = m;
    ht.n = 0;
    
    // Set gia tri mac dinh cho toan bo bang theo yeu cau de bai
    for (int i = 0; i < m; i++) {
        ht.table[i].MSHS = EMPTY; // EMPTY duoc dinh nghia la 0
        ht.table[i].HoTen = "";
        ht.table[i].Namsinh = 0;
        ht.table[i].Gioitinh = ' ';
        ht.table[i].Toan = 0;
        ht.table[i].Ly = 0;
        ht.table[i].Hoa = 0;
        ht.table[i].Anh = 0;
    }

    // 2. THEM HOC SINH VAO BANG
    for (int k = 0; k < n; k++) {
        Hocsinh currentHS = ds[k];
        int key = currentHS.MSHS;
        int i = 0; // Bien i dung cho cong thuc quadratic probing
        
        while (true) {
            // Cong thuc: h'(MSHS, i) = (h(MSHS) + i^2) % M
            int index = (key % m + i * i) % m;
            
            // Kiem tra xem o tai vi tri index co TRONG khong
            // O trong tuc la MSHS == EMPTY (bang 0)
            if (ht.table[index].MSHS == EMPTY) {
                // Tim thay cho trong -> Gan du lieu
                ht.table[index] = currentHS;
                ht.n++; // Tang so luong phan tu trong bang
                break;  // Ngat vong lap while de sang hoc sinh tiep theo
            }
            
            // Neu bi dung do (Collision) -> Tang i len de thu vi tri tiep theo
            i++;
        }
    }
}