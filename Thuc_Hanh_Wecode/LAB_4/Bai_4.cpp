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


bool isBST(TREE);

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
    if (isBST(r))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
	
//###INSERT CODE HERE -

// Ham phu tro duyet cay theo In-order (Trung tu: Left -> Root -> Right)
// prev: con tro luu lai Node da duyet ngay truoc do
bool checkBSTUtil(TREE root, TNode* &prev) {
    // 1. Dieu kien dung: Cay rong luon la BST
    if (root == NULL) return true;

    // 2. Duyet sang nhanh trai truoc
    if (!checkBSTUtil(root->left, prev)) return false;

    // 3. Xu ly Node hien tai
    // Neu ton tai node truoc do (prev != NULL) va gia tri hien tai <= gia tri truoc do
    // => Vi pham tinh chat tang dan cua BST
    if (prev != NULL && root->key <= prev->key) return false;

    // Cap nhat node hien tai thanh node "qua khu" de so sanh voi node tiep theo
    prev = root;

    // 4. Duyet sang nhanh phai
    return checkBSTUtil(root->right, prev);
}

bool isBST(TREE root) {
    TNode* prev = NULL; // Khoi tao node truoc do la NULL
    return checkBSTUtil(root, prev);
}