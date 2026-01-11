#include <iostream>
#include <vector>
using namespace std;

// 1. Sửa tham số adj để khớp với cách khai báo trong main
void dfs(const vector<vector<int>> &adj, vector<bool> &visited, int u)
{
    visited[u] = true;

    // Duyệt các đỉnh kề v của u
    for(int v : adj[u])
    {
        // 2. Dùng if thay cho while (trong DFS chỉ cần if là đủ)
        if(!visited[v])
        {
            dfs(adj, visited, v);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    // 3. Khai báo adj dạng vector lồng vector. 
    // Kích thước n + 1 để dùng được đỉnh từ 1 -> n mà không bị lỗi
    vector<vector<int>> adj(n + 1);
    
    // Tương tự, visited cũng cần n + 1 phần tử
    vector<bool> visited(n + 1, false);    

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int count = 0;

    // 4. Sửa vòng lặp: Duyệt qua chỉ số đỉnh (từ 1 đến n)
    for(int i = 1; i <= n; i++) 
    {
        if (!visited[i]) // Nếu đỉnh i chưa được thăm
        {
            count++; // Phát hiện một vùng liên thông mới
            dfs(adj, visited, i); // Loang ra hết vùng đó
        }
    }

    cout << count << endl; // In kết quả

    return 0;
}