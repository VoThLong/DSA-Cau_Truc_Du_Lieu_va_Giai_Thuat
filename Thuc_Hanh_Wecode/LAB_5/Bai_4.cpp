#include <iostream>
#include <vector>
using namespace std;

//Danh sach ke
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int u)
{
    visited[u] = true;
    //duyet qua cac diem khac noi den u
    for (int v : adj[u])
    {
        //Neu v chua duoc them
        if (!visited[v])
        {
        //Thi di tham cac diem noi tiep toi v
            dfs(v);
        }
    }
}


int main()
{   
    int m, n;
    cin >> m >> n;
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    adj.resize(m);
    visited.assign(m, false);

    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v]. push_back(u);
    }

    int count = 0;
    dfs(0);
    vector<int> out;
    for(int i = 0;  i < m; i++)
    {
        if(visited[i] && i != 0)
        {
            out.push_back(i);
        }
    }

    if(out.empty() == true)
    {
        cout << "KHONG";
    }
    else
    {
        for (int x : out)
        {
            cout << x << " ";
        }
    }

    return 0;
}