#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector <int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector <int> brr(m);
    for (int i = 0; i < m; i++)
    {
        cin >> brr[i];
    }

    sort(arr.begin(), arr.end());

    for(int i = 0; i < m; i++)
    {
        if(binary_search(arr.begin(), arr.end(), brr[i]))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    
    return 0;

}