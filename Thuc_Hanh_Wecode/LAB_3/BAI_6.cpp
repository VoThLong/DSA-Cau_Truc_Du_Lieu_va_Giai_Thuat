/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
sort
stable_sort
partial_sort
set
nth_element
priority_queue
sort_heap
multiset
map
multimap
###End banned keyword*/
// ###INSERT CODE HERE -

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void input_vector(vector<string> &arr, int n)
{
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void input_vector_pair(vector<pair<string, int>> &brr, vector<string> &arr, int n)
{
    int i = 0;
    while (i < n)
    {
        int count = 1;
        string current = arr[i];
        // Đếm số lần xuất hiện liên tiếp
        while (i + 1 < n && arr[i + 1] == current)
        {
            count++;
            i++;
        }
        brr.push_back({current, count});
        i++;
    }
}

// Hàm so sánh string như số
bool compareAsNumber(const string &a, const string &b)
{
    if (a.length() != b.length())
        return a.length() < b.length(); // Chuỗi ngắn hơn < chuỗi dài hơn
    return a < b;                       // Cùng độ dài thì so sánh từ điển
}

void Quick_Sort(vector<string> &arr, int left, int right)
{
    if (left >= right)
        return;

    int i = left, j = right;
    string pivot = arr[(left + right) / 2];

    while (i <= j)
    {
        while (compareAsNumber(arr[i], pivot))
            i++;
        while (compareAsNumber(pivot, arr[j]))
            j--;
        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (left < j)
        Quick_Sort(arr, left, j);
    if (i < right)
        Quick_Sort(arr, i, right);
}

void Quick_Sort_pair(vector<pair<string, int>> &brr, int left, int right)
{
    if (left >= right)
        return;

    int i = left, j = right;
    pair<string, int> pivot = brr[(left + right) / 2];

    while (i <= j)
    {
        // So sánh theo tần suất giảm dần, nếu bằng thì theo mã số tăng dần
        while (i < (int)brr.size() &&
               (brr[i].second > pivot.second ||
                (brr[i].second == pivot.second && compareAsNumber(brr[i].first, pivot.first))))
            i++;
        while (j >= 0 &&
               (brr[j].second < pivot.second ||
                (brr[j].second == pivot.second && compareAsNumber(pivot.first, brr[j].first))))
            j--;
        if (i <= j)
        {
            swap(brr[i], brr[j]);
            i++;
            j--;
        }
    }

    if (left < j)
        Quick_Sort_pair(brr, left, j);
    if (i < right)
        Quick_Sort_pair(brr, i, right);
}

void output_vector_pair(vector<pair<string, int>> &brr)
{
    for (const auto &p : brr)
    {
        cout << p.first << " " << p.second << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<string> arr;
    vector<pair<string, int>> brr;

    input_vector(arr, n);
    Quick_Sort(arr, 0, n - 1);
    input_vector_pair(brr, arr, n);
    Quick_Sort_pair(brr, 0, brr.size() - 1);
    output_vector_pair(brr);

    return 0;
}