/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/
#include <iostream>
#include <vector>

using namespace std;

struct TNode {
    int key;
    TNode * left, * right;
};

typedef TNode * TREE;

TREE CreateTree(vector<int> pre, vector<int> in, int preB, int preE, int inB, int inE) {
	int i;
	TREE root;
	if (inE < inB) return NULL;
	root = new TNode;
	if (root != NULL) {
		root->key = pre[preB];
		for (i = inB; i <= inE; i++)
			if (in[i] == pre[preB]) break;
		root->left = CreateTree(pre, in, preB+1, preE, inB, i - 1);
		root->right = CreateTree(pre, in, preB+i-inB+1, preE, i+1,inE);
	} return root;
}


int MaxGroup(TREE);

int main() {
    vector<int> nlr, lnr;
    int n, key;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> key;
        nlr.push_back(key);
    }

    for (int i = 0; i < n; i++) {
        cin >> key;
        lnr.push_back(key);
    }

    TREE r = CreateTree(nlr, lnr, 0, nlr.size()-1, 0, lnr.size()-1);
    cout << MaxGroup(r);
    return 0;
}

	
//###INSERT CODE HERE -

// Hàm phụ: Đi duyệt từng nút để tính tổng nhóm
void FindMaxGroup(TREE t, int &maxVal) {
    if (t == NULL) return; // Nếu nút rỗng thì quay về

    // 1. Tính tổng của nhóm hiện tại (Cha + các con)
    int currentSum = t->key;
    if (t->left != NULL) currentSum += t->left->key;
    if (t->right != NULL) currentSum += t->right->key;

    // 2. So sánh với kỷ lục hiện tại
    if (currentSum > maxVal) {
        maxVal = currentSum;
    }

    // 3. Tiếp tục đi xuống thăm các nhà bên dưới (đệ quy)
    FindMaxGroup(t->left, maxVal);
    FindMaxGroup(t->right, maxVal);
}

// Hàm chính (Theo tên trong template của bạn)
int MaxGroup(TREE t) {
    if (t == NULL) return 0;

    // Khởi tạo giá trị max ban đầu thật nhỏ (để số nào cũng lớn hơn nó)
    // -2e9 là xấp xỉ -2 tỷ (số int nhỏ nhất)
    int maxVal = -2000000000; 

    // Gọi hàm phụ đi tìm kiếm
    FindMaxGroup(t, maxVal);

    return maxVal;
}