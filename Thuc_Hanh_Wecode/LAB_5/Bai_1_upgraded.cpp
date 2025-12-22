#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int m, n;
    // Tăng tốc độ đọc ghi (Mẹo nhỏ cho các bài time limit thấp)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n;
    vector<int> arr(m, 0); // Mảng đếm bậc của đỉnh

    int u, v; // Biến tạm để lưu cạnh
    for (int i = 0; i < n; i++)
    {
        cin >> u >> v; // Đọc trực tiếp
        if (u != v) // Bỏ qua khuyên (nếu có)
        {
            arr[u]++;
            arr[v]++;
        }
    }

    int count = 0;
    for (int i = 0; i < m; i++)
    {
        if (arr[i] == 0) // Nếu bậc bằng 0 -> Đỉnh cô lập
        {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}