#ifndef Binary_Tree_H
#define Binary_Tree_H

template <class T>
class Binary_Tree
{
private:
    struct Node
    {
        T data;
        Node* left;
        Node* right; // Added semicolon here
    };

    //con tro goc cua cay
    Node* root;

    //ham da quy de chen
    Node* createNode(T val);

    //cac ham de quy chen
    void insert_recursive (Node* &node, int val);

    //cac ham de quy de duyet
    void inoder_recursive(Node* node);
    void preoder_recursive(Node* node);
    void postoder_recursive(Node* node);


public:
    Binary_Tree();
    ~Binary_Tree();

};

#endif
