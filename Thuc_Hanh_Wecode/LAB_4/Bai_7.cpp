/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/
#include <iostream>
#include <vector>

using namespace std;

struct TNode
{
    int key;
    TNode *left, *right;
};

typedef TNode *TREE;

TREE CreateTree(vector<int> pre, vector<int> in, int preB, int preE, int inB, int inE)
{
    int i;
    TREE root;
    if (inE < inB)
        return NULL;
    root = new TNode;
    if (root != NULL)
    {
        root->key = pre[preB];
        for (i = inB; i <= inE; i++)
            if (in[i] == pre[preB])
                break;
        root->left = CreateTree(pre, in, preB + 1, preE, inB, i - 1);
        root->right = CreateTree(pre, in, preB + i - inB + 1, preE, i + 1, inE);
    }
    return root;
}

int CountEvenLeaves(TREE);

int main()
{
    vector<int> nlr, lnr;
    int n, key;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> key;
        nlr.push_back(key);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> key;
        lnr.push_back(key);
    }

    TREE r = CreateTree(nlr, lnr, 0, nlr.size() - 1, 0, lnr.size() - 1);
    cout << CountEvenLeaves(r);
    return 0;
}

// ###INSERT CODE HERE -

int CountEvenLeaves(TREE t)
{
    // 1. Dieu kien dung (Base case): Neu node rong thi tra ve 0
    if (t == NULL)
        return 0;

    // 2. Kiem tra xem day co phai la Node La (Leaf Node) khong?
    // Dinh nghia: Node la la node KHONG co con trai va KHONG co con phai
    if (t->left == NULL && t->right == NULL)
    {
        // Neu la La roi, kiem tra tiep dieu kien CHAN
        if (t->key % 2 == 0)
        {
            return 1; // La chan -> Dem 1
        }
        return 0; // La le -> Khong dem
    }

    // 3. Buoc De quy (Recursive Step):
    // Neu khong phai la (tuc la node trung gian), tong so la chan se bang:
    // (So la chan ben nhanh trai) + (So la chan ben nhanh phai)
    return CountEvenLeaves(t->left) + CountEvenLeaves(t->right);
}