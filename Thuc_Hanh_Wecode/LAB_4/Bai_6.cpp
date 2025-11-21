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

void CreateTree(TREE &t)
{
    t = NULL;
}

TNode *CreateTNode(int x)
{
    TNode *p = new TNode;
    if (p == NULL)
        return NULL;
    p->left = p->right = NULL;
    p->key = x;
    return p;
}

void InsertNode(TREE &t, int x)
{
    TNode *p = CreateTNode(x);

    if (t == NULL)
    {
        t = p;
        return;
    }
    TREE q = t;
    while (q != NULL)
    {
        if (x == q->key)
            return;
        if (x > q->key)
        {
            if (q->right == NULL)
            {
                q->right = p;
                return;
            }
            q = q->right;
        }
        else
        {
            if (q->left == NULL)
            {
                q->left = p;
                return;
            }
            q = q->left;
        }
    }
}

void LoadTree(TREE &t)
{
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        InsertNode(t, k);
    }
}

int ComparisonCount(TREE, int);

int main()
{
    vector<int> keys;
    TREE t;
    CreateTree(t);
    LoadTree(t);
    int m, k;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> k;
        cout << ComparisonCount(t, k) << endl;
    }
    return 0;
}

// ###INSERT CODE HERE -

int ComparisonCount(TREE t, int x)
{
    int dem = 0; // Khoi tao bien dem so lan so sanh

    // Duyet cay tu goc xuong (Iterative approach - tiet kiem stack hon de quy)
    while (t != NULL)
    {
        dem++; // Moi lan vao loop tuc la ta thuc hien 1 phep so sanh (x vs t->key)

        if (x == t->key)
        {
            return dem; // Tim thay! Tra ve so buoc da di
        }

        if (x < t->key)
        {
            t = t->left; // Nho hon thi re trai
        }
        else
        {
            t = t->right; // Lon hon thi re phai
        }
    }

    return dem; // Truong hop khong tim thay (da di den duong cung)
}