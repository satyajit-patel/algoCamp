#include<bits/stdc++.h>
using namespace std;
// https://www.codechef.com/practice/course/strings/STRINGS/problems/WORDLE

void solve() {
    int t; cin>>t;
    while(t--) {
        string A,B; cin>>A>>B;
        
        int n = A.size();
        string ans = "";
        for(int i=0; i<n; i++) {
            if(A[i] == B[i]) {
                ans += 'G';
            } else {
                ans += 'B';
            }
        }
        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}