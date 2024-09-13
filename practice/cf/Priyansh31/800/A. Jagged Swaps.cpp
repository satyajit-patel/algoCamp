#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

void solve() {
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vi arr(n);
        for(auto& it: arr) {
            cin>>it;
        }
        
        if(arr[0] == 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    solve();
    return 0;
}