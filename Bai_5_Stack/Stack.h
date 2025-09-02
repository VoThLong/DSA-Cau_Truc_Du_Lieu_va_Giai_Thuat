#ifndef STACK_H
#define STACK_H
#define MAX_SIZE 100

#include <iostream>
#include <vector>

template <class T>
class Stack
{
    private:
        T arr[MAX_SIZE];
        int TopIndex;
    public:
        Stack();
        //khởi tạo CTDL Stack

        bool isEmpty();
        //Kiểm tra stack có rỗng không?

        bool isFull();
        //Kiểm tra stack có đầy không?

        void push(T value);
        //Thêm phần tử vào đầu danh sách

        void pop();
        //Xóa phần tử ở đầu

        T top();
        //Lấy giá trị đầu

};


#endif