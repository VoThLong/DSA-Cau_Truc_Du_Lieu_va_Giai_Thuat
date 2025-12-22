/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct TNode {
    int key;
    TNode *left, *right;
};

typedef TNode * TREE;

void CreateTree(TREE &t) {
    t = NULL;
}

TNode * CreateTNode(int x) {
    TNode * p = new TNode;
    if (p == NULL) return NULL;
    p->left = p->right = NULL;
    p->key = x;
    return p;
}

void InsertNode(TREE &t, int x) {
    TNode *p = CreateTNode(x);

    if (t == NULL) {
        t = p;
        return;
    }
    TREE q = t;
    while (q != NULL) {
        if (x == q->key) return;
        if (x > q->key) {
            if (q->right == NULL) {
                q->right = p;
                return;
            }
            q = q->right;
        }
        else {
            if (q->left == NULL) {
                q->left = p;
                return;
            }
            q = q->left;
        }
    }
}

void LoadTree(TREE &t) {
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        InsertNode(t, k);
    }
}

void MaxFindingCost(TREE);

int main()
{
    vector<int> keys;
    TREE t;
    CreateTree(t);
    LoadTree(t);
    MaxFindingCost(t);
    return 0;
}

	
//###INSERT CODE HERE -

int getHeight(TREE t)
{
    if (t == NULL) return -1;
    //De quy de truy xuat xuong cap duoi
    int MaxLeft = getHeight(t->left);
    int MaxRight = getHeight(t->right);
    return (MaxLeft > MaxRight ? MaxLeft : MaxRight) + 1;
}

void PrintNode(TREE t, int current, int target)
{
    if (t ==  NULL) return;
    if (current == target)
    {
        cout << t->key << " ";
    }
    
    PrintNode(t->left, current + 1, target);
    PrintNode(t->right, current + 1, target);
}

void MaxFindingCost(TREE t)
{
    int height = getHeight(t);
    PrintNode(t, 0, height);
}