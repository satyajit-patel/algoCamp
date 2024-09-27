#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
// https://www.hackerrank.com/contests/projecteuler/challenges/euler003/problem?isFullScreen=true

/*
    2 <= i <= 3 
    i=2
    n=5
    out of loop
    
    ----------------------------------
    
    
*/

void solve() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        
        int maxi = -1;
        for(int i=2; i*i<=n; i++) {
            if(n % i == 0) {
                maxi = max(maxi, i);
                while(n % i == 0) {
                    n /= i;
                }
            }
        }
        if(n > 1) {
            maxi = n;
        }
        cout << maxi << endl;
    }
}

signed main() {
  solve();
  return 0;
}
 
