#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<pair<string,long long>> RES;
int n;
string a[100005];
void Nhap();
void Merge(int l,int r, int mid);
void MergeP(int l, int r);
void MergeCount(int l,int r, int mid);
void MergePCount(int l, int r);
void Count();
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Nhap();
    MergeP(0,n-1);
    Count();
}
void Nhap()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
}
bool smallerNum(const string &a, const string &b) {
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b;
}
void Merge(int l,int r, int mid)
{
    int n1=mid-l+1, n2=r-mid;
    vector<string>L(n1),R(n2);
    for(int i=0;i<n1;i++)
        L[i] = a[l + i];
    for(int j=0;j<n2;j++)
        R[j] = a[mid + 1 + j];
    int i=0, j=0, k=l;
    while(i<n1&&j<n2)
    {
        if(smallerNum(L[i],R[j]))
        {
            a[k]=L[i];
            i++;
            k++;
        }
        else
        {
            a[k]=R[j];
            j++;
            k++;
        }
    }
    while(i<n1)
    {
        a[k]=L[i];
            i++;
            k++;
    }
    while(j<n2)
    {
        a[k]=R[j];
            j++;
            k++;
    }
}
void MergeP(int l, int r)
{
    if(l>=r) return;
    int mid=(l+r)/2;
    MergeP(l, mid);
    MergeP(mid+1, r);
    Merge(l,r,mid);
}
void MergeCount(int l,int r, int mid)
{
    int n1=mid-l+1, n2=r-mid;
    vector<pair<string,long long>>L(n1),R(n2);
    for(int i=0;i<n1;i++)
        L[i] = RES[l + i];
    for(int j=0;j<n2;j++)
        R[j] = RES[mid + 1 + j];
    int i=0, j=0, k=l;
    while(i<n1&&j<n2)
    {
        if((L[i].second>R[j].second)||(L[i].second==R[j].second && smallerNum(L[i].first,R[j].first)))
        {
            RES[k]=L[i];
            i++;
            k++;
        }
        else
        {
            RES[k]=R[j];
            j++;
            k++;
        }
    }
    while(i<n1)
    {
        RES[k]=L[i];
            i++;
            k++;
    }
    while(j<n2)
    {
        RES[k]=R[j];
            j++;
            k++;
    }
}
void MergePCount(int l, int r)
{
    if(l>=r) return;
    int mid=(l+r)/2;
    MergePCount(l, mid);
    MergePCount(mid+1, r);
    MergeCount(l,r,mid);
}
void Count()
{
    if(n == 0) return;  // ✅ Thêm kiểm tra edge case
    
    RES.push_back({a[0],1});
    int k=0;  // ✅ Bắt đầu từ 0 (index của phần tử vừa thêm)
    for(int i=1;i<n;i++)
    {
        if(a[i]!=a[i-1])
        {
            RES.push_back({a[i],1});
            k++;  // ✅ Tăng k SAU khi push_back
        }
        else RES[k].second++;  // ✅ Truy cập RES[k] trực tiếp
    }
    MergePCount(0,RES.size()-1);
    for(int i=0;i<RES.size();i++)
        cout<<RES[i].first<<" "<<RES[i].second<<'\n';
}