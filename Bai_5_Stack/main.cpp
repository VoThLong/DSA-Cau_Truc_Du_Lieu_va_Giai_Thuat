#include <iostream>
#include "Stack.h"

int main() {
    Stack<int> stack;

    std::cout << "Stack co rong khong? " << (stack.isEmpty() ? "Co" : "Khong") << std::endl;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Stack sau khi them 3 phan tu: ";
    stack.print();

    std::cout << "Phan tu dau cua stack: " << stack.top() << std::endl;

    stack.pop();

    std::cout << "Stack sau khi xoa 1 phan tu: ";
    stack.print();

    std::cout << "Stack co day khong? " << (stack.isFull() ? "Co" : "Khong") << std::endl;

    return 0;
}
