#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>

// https://www.hackerrank.com/contests/projecteuler/challenges/euler004/problem?isFullScreen=true

int rev(int n) {
    int ans = 0;
    while(n) {
        int lastDigit = n % 10;
        n /= 10;
        ans = (ans * 10) + lastDigit;
    }
    return ans;
}

bool ispal(int n) {
    return n == rev(n);
}

void solve() {
  int n; cin >> n;  
    
  int maxi = -1;
  for(int i=999; i>99; i--) { // only 3 digit num
      for(int j=999; j>99; j--) {
          int res = i * j;
          if(ispal(res) && res < n) {
              maxi = max(maxi, res);
          }
      }
  }
  cout << maxi << endl;
}

signed main() {
  // solve();
  int t; cin >> t;
  while(t--) {
      solve();
  }
  return 0;
}
