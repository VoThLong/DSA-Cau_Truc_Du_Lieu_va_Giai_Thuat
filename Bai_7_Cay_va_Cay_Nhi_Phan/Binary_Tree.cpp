#include <iostream>
using namespace std;

// --- PHẦN 1: ĐỊNH NGHĨA CẤU TRÚC ---

class BinaryTree {
private:
    // Cấu trúc một cái Nút (Node)
    struct Node {
        int data;       // Dữ liệu
        Node* left;     // Con trỏ sang con trái
        Node* right;    // Con trỏ sang con phải
    };

    Node* root; // Gốc của cây

    // Hàm phụ trợ để tạo nhanh một node mới (Cấp phát bộ nhớ)
    Node* createNode(int value) {
        Node* p = new Node;
        p->data = value;
        p->left = nullptr;
        p->right = nullptr;
        return p;
    }

    // --- CÁC HÀM DUYỆT ĐỆ QUY (Nội bộ dùng) ---

    // 1. Duyệt Trước (NLR): Cha -> Trái -> Phải [cite: 759]
    void preorder_recursive(Node* node) {
        if (node != nullptr) {
            cout << node->data << " ";      // N: Thăm Cha trước
            preorder_recursive(node->left); // L: Đi Trái
            preorder_recursive(node->right);// R: Đi Phải
        }
    }

    // 2. Duyệt Giữa (LNR): Trái -> Cha -> Phải [cite: 760]
    void inorder_recursive(Node* node) {
        if (node != nullptr) {
            inorder_recursive(node->left);  // L: Đi Trái
            cout << node->data << " ";      // N: Thăm Cha ở giữa
            inorder_recursive(node->right); // R: Đi Phải
        }
    }

    // 3. Duyệt Sau (LRN): Trái -> Phải -> Cha [cite: 761]
    void postorder_recursive(Node* node) {
        if (node != nullptr) {
            postorder_recursive(node->left); // L: Đi Trái
            postorder_recursive(node->right);// R: Đi Phải
            cout << node->data << " ";       // N: Thăm Cha cuối cùng
        }
    }

public:
    // Constructor: Khởi tạo cây rỗng
    BinaryTree() {
        root = nullptr;
    }

    // --- HÀM TẠO CÂY THỦ CÔNG (Cho cây thường) ---
    // Vì cây thường không tự biết trái nhỏ phải lớn, ta phải tự nối
    void build_example_tree() {
        /* Mô phỏng cây trong ví dụ:
              1  (Gốc - A)
             / \
            2   3 (B, C)
           / \
          4   5 (D, E)
        */
        
        // 1. Tạo Gốc
        root = createNode(1);

        // 2. Tạo 2 con của Gốc
        root->left = createNode(2);
        root->right = createNode(3);

        // 3. Tạo con cho Node 2 (Bên trái)
        root->left->left = createNode(4);
        root->left->right = createNode(5);

        cout << "-> Da xay xong cay thu cong!" << endl;
    }

    // --- CÁC HÀM GỌI TỪ BÊN NGOÀI (PUBLIC) ---
    
    void print_preorder() {
        cout << "Duyet Truoc (NLR): ";
        preorder_recursive(root);
        cout << endl;
    }

    void print_inorder() {
        cout << "Duyet Giua  (LNR): ";
        inorder_recursive(root);
        cout << endl;
    }

    void print_postorder() {
        cout << "Duyet Sau   (LRN): ";
        postorder_recursive(root);
        cout << endl;
    }
};

// --- PHẦN 2: CHƯƠNG TRÌNH CHÍNH (MAIN) ---

int main() {
    BinaryTree myTree;

    // 1. Xây cây mẫu
    myTree.build_example_tree();

    // 2. In ra các kiểu duyệt để kiểm tra
    // Với cây: 1(gốc), 2(trái), 3(phải), 4(trái của 2), 5(phải của 2)
    
    myTree.print_preorder();  
    // Kỳ vọng NLR: 1 -> 2 -> 4 -> 5 -> 3
    
    myTree.print_inorder();   
    // Kỳ vọng LNR: 4 -> 2 -> 5 -> 1 -> 3
    
    myTree.print_postorder(); 
    // Kỳ vọng LRN: 4 -> 5 -> 2 -> 3 -> 1

    return 0;
}