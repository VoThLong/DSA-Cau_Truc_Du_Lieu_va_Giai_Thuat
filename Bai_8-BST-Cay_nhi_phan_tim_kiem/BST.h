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

public:
    BST();
    void insert(int value);
    

};

#endif
