#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> arr(m, vector<int>(m, 0));
    for(int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
        arr[start][end] = 1;
        arr[end][start] = 1;
    }

    
}