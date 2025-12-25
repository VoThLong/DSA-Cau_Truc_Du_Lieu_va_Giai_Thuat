#include <iostream>
#include "BST.h"
using namespace std;

int main()
{
    BST tree;
    
    // 1. Tạo cây mẫu: 50, 30, 20, 40, 70, 60, 80
    /* Hình dạng cây:
            50
           /  \
         30    70
        /  \  /  \
       20  40 60  80
    */
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    cout << "--- KET QUA DUYET CAY ---" << endl;
    tree.PrintInOrder();   // Kỳ vọng: 20 30 40 50 60 70 80
    cout << endl;
    tree.PrintPreOrder();  // Kỳ vọng: 50 30 20 40 70 60 80
    cout << endl;
    tree.PrintPostOrder(); // Kỳ vọng: 20 40 30 60 80 70 50
    cout << endl;

    cout << "\n--- TEST TIM KIEM ---" << endl;
    int x = 60;
    if (tree.Search(x))
        cout << "Tim thay so " << x << " trong cay!" << endl;
    else
        cout << "Khong tim thay so " << x << endl;

    int y = 99;
    if (tree.Search(y))
        cout << "Tim thay so " << y << " trong cay!" << endl;
    else
        cout << "Khong tim thay so " << y << endl;

    return 0;
}