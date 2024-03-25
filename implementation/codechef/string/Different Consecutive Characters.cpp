#include<bits/stdc++.h>
using namespace std;
// https://www.codechef.com/practice/course/strings/STRINGS/problems/DIFFCONSEC

void solve() {
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        string s; cin>>s;
        
        int ans = 0;
        for(int i=1; i<n; i++) {
            if(s[i] == s[i-1]) {
                ans++;
            }
        }
        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}