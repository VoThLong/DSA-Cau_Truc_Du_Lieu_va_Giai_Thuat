/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/
#include <iostream>
#include <vector>

using namespace std;

struct Hocsinh{
    string Hodem, Ten;
    bool Gioitinh;
    int Ngay, Thang, Nam;
    double Toan, Van, Ly, Hoa, Anh, Sinh;
};

void InputElement(Hocsinh &x) {
    getline(cin>>ws, x.Hodem);
    getline(cin>>ws, x.Ten);
    cin >> x.Gioitinh;
    cin >> x.Ngay >> x.Thang >> x.Nam;
    cin >> x.Toan >> x.Van >> x.Ly >> x.Hoa >> x.Anh >> x.Sinh;
}

void OutputElement(Hocsinh hs) {
    cout << hs.Hodem
            << ' ' << hs.Ten
            << '\t' << hs.Gioitinh
            << '\t' << hs.Ngay
            << '/' << hs.Thang
            << '/' << hs.Nam
            << '\t' << hs.Toan
            << '\t' << hs.Van
            << '\t' << hs.Ly
            << '\t' << hs.Hoa
            << '\t' << hs.Anh
            << '\t' << hs.Sinh << endl;;
}

void Output(vector<Hocsinh> ls) {
    for (int i = 0; i < ls.size(); i++) {
        OutputElement(ls[i]);
    }
}

void Input(vector<Hocsinh> &ls) {
    int n;
    cin >> n;
    Hocsinh hs;
    for (int i = 0; i < n; i++) {
        InputElement(hs);
        ls.push_back(hs);
    }
}

void Sort(vector<Hocsinh> &ls);

int main()
{
    vector<Hocsinh> ls;
    Input(ls);
    Sort(ls);
    Output(ls);
    return 0;
}

//###INSERT CODE HERE -

// bool Compare(Hocsinh a, Hocsinh b)
// {
//     if ((a. Toan + a. Van + a.Ly + a.Hoa + a.Anh + a.Sinh)/6 < (b.Toan + b.Van + b.Ly + b.Hoa + b.Anh + b.Sinh)/6)
//     {
//         return false;
//     }
//     else if ((a. Toan + a. Van + a.Ly + a.Hoa + a.Anh + a.Sinh)/6 > (b.Toan + b.Van + b.Ly + b.Hoa + b.Anh + b.Sinh)/6)
//     {
//         return true;
//     }
//     else
//     {
//         if (a.Nam < b.Nam)
//         {
//             return false;
//         }
//         else if (a.Nam > b.Nam)
//         {
//             return true;
//         }
//         else
//         {
//             if (a.Thang < b.Thang)
//             {
//                 return false;
//             }
//             else if (a.Thang > b.Thang)
//             {
//                 return true;
//             }
//             else
//             {
//                 if (a.Ngay < b.Ngay)
//                 {
//                     return false;
//                 }
//                 else if (a.Ngay > b.Ngay)
//                 {
//                     return true;
//                 }
//                 else
//                 {
//                     return false;
//                 }
//             }
//         }
//     }
// }

// void Sort(vector<Hocsinh> &ls) {
//     int n = ls.size();
//     // Sử dụng thuật toán Bubble Sort để đảm bảo tính ổn định (stable sort)
//     for (int i = 0; i < n - 1; i++) 
//     {
//         bool swapped = false;
//         for (int j = 0; j < n - i - 1; j++) 
//         {
//             if (Compare(ls[j+1], ls[j])) 
//             {
//                 Hocsinh temp = ls[j];
//                 ls[j] = ls[j+1];
//                 ls[j+1] = temp;
//                 swapped = true;
//             }
//         }
//         if (!swapped) 
//         {
//             break; // If no two elements were swapped, the array is sorted
//         }
//     }
// }

void Sort(vector<Hocsinh> &ls) {
    int n = ls.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            
            double tb1 = (ls[j].Toan + ls[j].Van + ls[j].Ly + 
                         ls[j].Hoa + ls[j].Anh + ls[j].Sinh) / 6.0;
            
            double tb2 = (ls[j+1].Toan + ls[j+1].Van + ls[j+1].Ly + 
                         ls[j+1].Hoa + ls[j+1].Anh + ls[j+1].Sinh) / 6.0;
            
            bool needSwap = false;
            
            // So sánh giảm dần theo điểm trung bình
            if (tb2 > tb1) {
                needSwap = true;
            }
            // Nếu điểm bằng nhau, so sánh tăng dần theo tuổi (ngày sinh nhỏ hơn xếp sau)
            else if (tb1 == tb2) {
                // Người sinh sau (nhỏ tuổi hơn) xếp trước -> ngày sinh lớn hơn xếp trước
                if (ls[j+1].Nam > ls[j].Nam) {
                    needSwap = true;
                }
                else if (ls[j+1].Nam == ls[j].Nam) {
                    if (ls[j+1].Thang > ls[j].Thang) {
                        needSwap = true;
                    }
                    else if (ls[j+1].Thang == ls[j].Thang) {
                        if (ls[j+1].Ngay > ls[j].Ngay) {
                            needSwap = true;
                        }
                    }
                }
            }
            

            if (needSwap) {
                Hocsinh temp = ls[j];
                ls[j] = ls[j+1];
                ls[j+1] = temp;
                swapped = true;
            }
        }
        
        // Nếu không có gì thay đổi thì mảng đã sắp xếp xong, thoát sớm
        if (!swapped) {
            break;
        }
    }
}