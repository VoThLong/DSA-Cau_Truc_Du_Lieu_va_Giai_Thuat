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
//###INSERT CODE HERE -

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<bool> present(n + 1, false);
    
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x <= n){
            present[x] = true;
        }
    }
    
    int mex = 0;
    while(mex <= n && present[mex]){
        mex++;
    }
    
    cout << mex << endl;
    
    return 0;
}