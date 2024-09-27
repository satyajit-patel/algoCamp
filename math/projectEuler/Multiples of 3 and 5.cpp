#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
// https://www.hackerrank.com/contests/projecteuler/challenges/euler001/problem?isFullScreen=true

int f(int n, int d) {
    /*
        formula of any "Arithmatic Progression"
        which increases constantly
        like: 
        3's mul -> 0 3 6 9 12 15 18 21 24 27 30
        5's mul -> 0, 5, 10, 15, 20, 25, 30, 35
        common  -> 0, 15, 30
        i.e
        a + (a + 1d) + (a + 2d) + (a + 3d) + (a + 4d) 
    */
    n /= d;
    return (n*(n+1)*d)/2;
}

void solve() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        
        n--; // excluding n
        int sum = f(n, 3) + f(n, 5) - f(n, 15);
        // add both multiple of 3 & 5 and substrac the 
        // common element (LCM)
        cout << sum << endl;
    }
}

signed main() {
  solve();
  return 0;
}
