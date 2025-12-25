#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const double coll_rate = 0.33;
string solve_hash_table(int n,int m,const vector<int> &keys)
{
    vector<vector<int>> hashtable(m);
    int coll_count = 0;
    for(int key:keys)
    {
        int i = key % m;
        if (!hashtable[i].empty()) {
            coll_count++;
        }
            hashtable[i].push_back(key);
    }
    double kcr;
    if(n>0)
    {
        kcr=(double)coll_count/n;
    }
    else kcr=0;
    if(kcr>coll_rate)
    {
        return "BAD";
    }
    else return "GOOD";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector <int> keys(n);
    for(int i=0;i<n;i++)
    {
        cin>>keys[i];
    }
    string result =  solve_hash_table(n, m, keys);
    cout << result << endl;
    return 0;
} //tỉ lệ đụng đọo