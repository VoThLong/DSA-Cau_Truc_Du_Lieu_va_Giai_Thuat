#include <iostream>
#include <vector>

using namespace std;

template <class Object>
void Swap(Object &a, Object &b) {
    Object temp = a;
    a = b;
    b = temp;
}

