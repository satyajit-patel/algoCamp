#include<bits/stdc++.h>
using namespace std;

// https://www.codechef.com/practice/course/arrays-strings-sorting/INTARR01/problems/DOMINANT2

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
        
        int maxi = INT_MIN;
        int maxi_ele = -1;
        for(auto& it: mp) {
            if(it.second > maxi) {
                maxi = it.second;
                maxi_ele = it.first;
            }
        }
        
        bool ok = true;
        for(auto& it: mp) {
            if(it.second == maxi && it.first != maxi_ele) {
                ok = false;
                break;
            }
        }
        
        if(ok) {
            cout<<"YES\n";
        } else {
            cout<<"NO\n";
        }
    }
}

int main() {
    solve();
    return 0;
}