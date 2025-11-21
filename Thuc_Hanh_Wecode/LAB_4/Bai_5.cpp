/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
[
]
###End banned keyword*/
#include <iostream>

using namespace std;

struct Hocsinh{
    string Hodem, Ten;
    bool Gioitinh;
    int Ngay, Thang, Nam;
    double Toan, Van, Ly, Hoa, Anh, Sinh;
};

void InputElement(Hocsinh &x) {
    getline(cin>>ws, x.Hodem);
    getline(cin>>ws, x.Ten);
    cin >> x.Gioitinh;
    cin >> x.Ngay >> x.Thang >> x.Nam;
    cin >> x.Toan >> x.Van >> x.Ly >> x.Hoa >> x.Anh >> x.Sinh;
}

void OutputElement(Hocsinh hs) {
    cout << hs.Hodem
            << ' ' << hs.Ten
            << '\t' << hs.Gioitinh
            << '\t' << hs.Ngay
            << '/' << hs.Thang
            << '/' << hs.Nam
            << '\t' << hs.Toan
            << '\t' << hs.Van
            << '\t' << hs.Ly
            << '\t' << hs.Hoa
            << '\t' << hs.Anh
            << '\t' << hs.Sinh << endl;
}

struct TNode {
    Hocsinh data;
    TNode * left, * right;
};

typedef TNode * TREE;

void CreateTree(TREE &r) {
    r = NULL;
}

TNode * CreateTNode(Hocsinh x) {
    TNode * p = new TNode;
    if (p == NULL) exit(1);
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}


//###INSERT CODE HERE -

// Ham so sanh 2 hoc sinh theo yeu cau de bai
// Tra ve: 1 neu a > b, -1 neu a < b, 0 neu a == b
int CompareHS(Hocsinh a, Hocsinh b) {
    if (a.Ten > b.Ten) return 1;
    if (a.Ten < b.Ten) return -1;
    
    // Neu ten bang nhau, xet tiep Ho dem
    if (a.Hodem > b.Hodem) return 1;
    if (a.Hodem < b.Hodem) return -1;
    
    return 0; // Trung nhau hoan toan
}

// Ham them mot hoc sinh vao cay BST
void InsertNode(TREE &root, Hocsinh x) {
    if (root == NULL) {
        root = CreateTNode(x);
    } else {
        int result = CompareHS(x, root->data);
        
        if (result == -1) {
            // Neu x nho hon root -> sang trai
            InsertNode(root->left, x);
        } else if (result == 1) {
            // Neu x lon hon root -> sang phai
            InsertNode(root->right, x);
        }
        // Neu result == 0 (trung nhau) thi khong lam gi ca (theo de bai)
    }
}

// Duyet cay theo LNR (In-order) de xuat ra danh sach tang dan
void TraverseLNR(TREE root) {
    if (root == NULL) return;
    
    TraverseLNR(root->left);   // Duyet con trai
    OutputElement(root->data); // In goc
    TraverseLNR(root->right);  // Duyet con phai
}

int main() {
    TREE t;
    CreateTree(t);
    
    int n;
    cin >> n; // Nhap so luong hoc sinh
    
    // Vong lap nhap va them truc tiep vao cay (khong dung mang luu tru)
    Hocsinh tempHS;
    // Khong dung bien chay i++ trong for vi de bai cam 
    // Ta dung while hoac for binh thuong deu duoc, mien ko khai bao mang
    for (int i = 0; i < n; i++) {
        InputElement(tempHS);
        InsertNode(t, tempHS);
    }
    
    // Xuat ket qua duyet LNR
    TraverseLNR(t);
    
    return 0;
}