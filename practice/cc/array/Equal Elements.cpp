#include<bits/stdc++.h>
using namespace std;

// https://www.codechef.com/practice/course/arrays-strings-sorting/INTARR01/problems/EQUALELE?tab=statement

void solve() {
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        int arr[n];
        for(int i=0; i<n; i++) {
            cin>>arr[i];
        }
        
        map<int, int> mp;
        for(int i=0; i<n; i++) {
            mp[arr[i]]++;
        }
        
        set<int> st;
        for(auto& it: mp) {
            st.insert(it.second);
        }
        cout<<n - *st.rbegin() <<endl;
    }
}

int main() {
    solve();
    return 0;
}