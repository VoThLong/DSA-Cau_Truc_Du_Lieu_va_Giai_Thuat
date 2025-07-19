#include <iostream>
#include <string>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) 
    {
        cin >> a[i]; 
    }
//Duyệt mảng 
    for (int i = 0; i < n; i++) 
    {
        cout << a[i] << ' '; 
    }
//Range based for loop
    cout << endl;
    for (int x : a) 
    {
        cout << x << ' '; 
    }
    cout << endl;
/*Vòng lặp for (int x : a) là một cách viết tắt trong C++11 để duyệt qua tất cả các phần tử của một tập hợp (trong trường hợp này là mảng a).

Ở mỗi lần lặp, biến x sẽ tự động được gán bằng giá trị của một phần tử trong mảng a, lần lượt từ đầu đến cuối.*/
    for (int x : a) 
    {
        x = 100; 
    }
    cout << endl;

    for (int x : a) 
    {
        cout << x << ' '; 
    }
    cout << endl;
return 0;
}