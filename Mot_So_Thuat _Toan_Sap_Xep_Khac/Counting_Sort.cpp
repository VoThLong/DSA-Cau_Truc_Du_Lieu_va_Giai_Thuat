#include <iostream>
using namespace std;

int Max_Value(int arr[], int n)
{
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxVal)
        {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

void Counting_Sort(int arr[], int n)
{
    int maxVal = Max_Value(arr, n);
    int* count = new int[maxVal + 1](); // Khởi tạo mảng đếm với giá trị 0
    int* output = new int[n]; // Mảng để lưu kết quả sắp xếp

    // Đếm số lần xuất hiện của mỗi phần tử
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    // Cập nhật mảng đếm để chứa vị trí cuối cùng của mỗi phần tử trong mảng output
    for (int i = 1; i <= maxVal; i++)
    {
        count[i] += count[i - 1];
    }

    // Xây dựng mảng output
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Sao chép mảng output trở lại mảng arr
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }

    // Giải phóng bộ nhớ
    delete[] count;
    delete[] output;
}

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

int main()
{
    int arr[100], n;
    Input(arr, n);
    Counting_Sort(arr, n);
    Output(arr, n);
    return 0;
}