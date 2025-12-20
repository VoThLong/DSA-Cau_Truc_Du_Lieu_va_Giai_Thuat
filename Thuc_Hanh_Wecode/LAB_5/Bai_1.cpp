#include <iostream>
#include <vector>
using namespace std;

struct line
{
    int start, end;
};

int main()
{
    int m, n;
    cin >> m >> n;
    vector<int> arr(m, 0);
    vector<line> lines(n);
    for (int i = 0; i < n; i++)
    {
        cin >> lines[i].start >> lines[i].end;
        if (lines[i].start != lines[i].end)
        {
            arr[lines[i].start]++;
            arr[lines[i].end]++;
        }
    }
    int count = 0;
for (int i = 0; i < m; i++)
{
    if (arr[i] == 0)
    {
        count++;
    }
}
cout << count << endl;
    return 0;

}