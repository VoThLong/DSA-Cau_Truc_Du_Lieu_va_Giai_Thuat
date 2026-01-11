#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[1001]; // Danh sách kề

bool visited[1001]; // Mảng đánh dấu

void dfs(int u) {
    cout << u << " ";   // 1. In ra đỉnh đang đứng
    visited[u] = true;  // 2. Đánh dấu là đã đi qua rồi

    // 3. Duyệt qua các hàng xóm (v) của u
    for (int v : adj[u]) {
        if (!visited[v]) { // Nếu v chưa từng đi qua
            // ... CODE CỦA BẠN Ở ĐÂY ...
            // (Gợi ý: Gọi đệ quy hàm dfs cho đỉnh v)
            dfs(v);
        }
    }
}

bool visited2[1001];

void bfs(int s) { // s là đỉnh bắt đầu
    queue<int> q;
    
    // Bước 1: Đẩy đỉnh đầu tiên vào hàng đợi và đánh dấu
    q.push(s);
    visited[s] = true;

    // Bước 2: Lặp khi hàng đợi chưa rỗng
    while (!q.empty()) {
        
        // 1. Lấy đỉnh đầu hàng ra lưu vào biến u
        // 2. Xóa đỉnh đó khỏi hàng đợi
        // 3. In u ra màn hình
        int u = q.front();
        q.pop();
        cout << u << ' ';

        // Bước 3: Duyệt các hàng xóm của u
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v); // Mời hàng xóm vào xếp hàng
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m; 
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        // Code chuẩn:
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    
    return 0;
}