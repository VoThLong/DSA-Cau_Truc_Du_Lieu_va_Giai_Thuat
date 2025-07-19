#include <iostream>
#include <vector>

#include <thread>
#include <chrono>

#include "Linked_List.h"
using namespace std;

int main()
{
    int choice = 0;
    int n, pos;
    LinkedList LL;
    cout << "Xin chào người dùng. Hãy nhập các thao tác sau: \n";
    do {
        cout << "------------------------------------------------------\n";
        cout << "\n1. Thêm vào đầu danh sách liên kết \n";
        cout << "2. Thêm vào cuối danh sách liên kết \n";
        cout << "3. Thêm vào vị trí bất kỳ trong danh sách liên kết \n";
        cout << "4. Hiển thị danh sách liên kết \n";
        cout << "5. Tìm kiếm giá trị\n";
        cout << "6. Xóa phần tử tại vị trí\n";
        cout << "7. Thoát \n";
        cout << "Kích thước của danh sách hiện tại là: " << LL.getSize() << endl;
        cout << "------------------------------------------------------\n";
        cout << "Lựa chọn của bạn: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Nhập vào giá trị cần thêm đầu: ";
                cin >> n;
                LL.AddHead(n);
                break;
            case 2:
                cout << "Nhập vào giá trị cần thêm cuối: ";
                cin >> n;
                LL.AddTail(n);
                break;
            case 3:
                cout << "Nhập vào giá trị cần thêm: ";
                cin >> n;
                cout << "Nhập vào vị trí cần thêm: ";
                cin >> pos;
                LL.AddPosition(n, pos);
                break;
            case 4:
                LL.display();
                break;
            case 5: 
            {
                cout << "Nhập vào giá trị cần tìm: ";
                cin >> n;
                vector<int> tmp;
                tmp = LL.SearchAll(n);
                if(tmp.empty())
                {
                    cout << "Không có giá trị cần tìm.\n";
                }
                else
                {
                    cout << "Giá trị tìm kiếm nằm ở (các) vị trí: ";
                    for(int x : tmp)
                    {
                        cout << x << " ";
                    }
                    cout << endl;
                }
            }
                break;
            case 6:
                LL.display();
                cout << "Nhập vào vị trí cần xóa: ";
                cin >> n;
                LL.Remove(n);
                break;
            case 7:
                cout << "Đang thoát chương trình...\n";

                this_thread::sleep_for(chrono::milliseconds(1500)); // Delay 1.5 giây
                
                break;
            default:
                cout << "Lựa chọn không hợp lệ! Mời nhập lại. \n";
        }
    } while (choice != 7);
    return 0;
}