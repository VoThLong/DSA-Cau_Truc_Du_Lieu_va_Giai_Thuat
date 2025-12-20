#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> arr(m, vector<int>(m, 0));
    vector<bool> Check(m, 0);
    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
        arr[start][end] = 1;
        arr[end][start] = 1; // Thêm dòng này để đồ thị trở thành vô hướng
        if (start != end && start == 0)
        {
            Check[end] = 1;
            Check[start] = 1; // Đỉnh 0 cũng có thể đến được từ các đỉnh kề
        }
    }

    bool changed = 0;
    do
    {
        changed = 0;
        for (int i = 0; i < m; i++)
        {
            if (Check[i] == 1)
            {
                for (int j = 0; j < m; j++)
                {
                    if (arr[i][j] == 1 && Check[j] == 0)
                    {
                        Check[j] = 1;
                        changed = 1;
                    }
                }
            }
        }
    }
    while (changed == 1);
    
    for (int i = 1; i < m; i++)
    {
        if (Check[i] == 1)
        {
            cout << "CO" << endl;
        }
        else
        {
            cout << "KHONG" << endl;
        }
    }
    return 0;
}
