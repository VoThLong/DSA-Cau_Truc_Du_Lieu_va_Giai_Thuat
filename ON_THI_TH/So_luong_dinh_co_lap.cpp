#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> Points(m);

    for(int i = 0; i < n; i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        if (temp1 != temp2)
        {
            Points[temp1].push_back(temp2);
            Points[temp2].push_back(temp1);
        }
    }
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(Points[i].empty())
        {count++;}
    }
    cout << count << endl;

    return 0;
}