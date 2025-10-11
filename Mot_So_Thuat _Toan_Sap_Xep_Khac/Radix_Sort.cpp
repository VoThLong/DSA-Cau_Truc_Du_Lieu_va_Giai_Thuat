#include <iostream>>
using namespace std;

void Input(int arr[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void Output(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Radix_Sort(int arr[], int n)
{
    cout << "Mang ban dau: ";
    Output(arr, n);
    cout << endl;
    
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxVal)
        {
            maxVal = arr[i];
        }
    }
    
    cout << "Gia tri lon nhat: " << maxVal << endl << endl;

    // Hàm phụ để thực hiện Counting Sort theo chữ số cụ thể
    auto countingSortByDigit = [&](int exp) {
        int* output = new int[n]; // Mảng để lưu kết quả tạm thời
        int count[10] = {0}; // Mảng đếm cho các chữ số từ 0 đến 9

        // Hiển thị chữ số đang sắp xếp
        string digitName;
        if (exp == 1) digitName = "hang don vi";
        else if (exp == 10) digitName = "hang chuc";
        else if (exp == 100) digitName = "hang tram";
        else if (exp == 1000) digitName = "hang nghin";
        else digitName = "hang " + to_string(exp);
        
        cout << "Sap xep theo " << digitName << " (exp = " << exp << "):" << endl;
        
        // Hiển thị chữ số của từng phần tử
        cout << "  Chu so: ";
        for (int i = 0; i < n; i++)
        {
            int digit = (arr[i] / exp) % 10;
            cout << digit << " ";
        }
        cout << endl;

        // Đếm số lần xuất hiện của mỗi chữ số
        for (int i = 0; i < n; i++)
        {
            int digit = (arr[i] / exp) % 10;
            count[digit]++;
        }

        // Cập nhật mảng đếm để chứa vị trí cuối cùng của mỗi chữ số trong mảng output
        for (int i = 1; i < 10; i++)
        {
            count[i] += count[i - 1];
        }

        // Xây dựng mảng output
        for (int i = n - 1; i >= 0; i--)
        {
            int digit = (arr[i] / exp) % 10;
            output[count[digit] - 1] = arr[i];
            count[digit]--;
        }

        // Sao chép mảng output trở lại mảng arr
        for (int i = 0; i < n; i++)
        {
            arr[i] = output[i];
        }

        // Hiển thị kết quả sau mỗi bước
        cout << "  Ket qua: ";
        Output(arr, n);
        cout << endl;

        delete[] output;
    };

    // Thực hiện Counting Sort cho mỗi chữ số, bắt đầu từ chữ số ít quan trọng nhất
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
    {
        countingSortByDigit(exp);
    }
    
    cout << "Mang sau khi sap xep: ";
    Output(arr, n);
}

int main()
{
    int arr[100], n;
    Input(arr, n);
    Radix_Sort(arr, n);
    Output(arr, n);
    return 0;
}