#ifndef BST_H
#define BST_H

class BST
{
private:
//CTDL Node
    struct Node
    {
        int data;
        Node* left;
        Node* right; 
    };
// Node goc
    Node* root;

//Tao node
    Node* createnode(int value);

//Them node
    void insert_recursive(Node* &node, int value);
//Tim node
    bool SearchRecursive(Node *node, int value);
//Duyệt cây 
//Duyet giua (InOrder) - LNR
void InOrderRecursive(Node *node);
//Duyet truoc (Preorder) - NLR
void PreOrderRecursive(Node *node);
//Duyet sau (PostOrder) - LRN
void PostOrderRecursive(Node *node);



public:
    BST();
    void insert(int value);
    bool Search(int value);
    void PrintInOrder();
    void PrintPreOrder();
    void PrintPostOrder();
};

#endif
