#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>

void solve() {
  // https://codeforces.com/problemset/problem/2004/B
  int t; cin>>t;
  while(t--) {
    int l, r; cin>>l>>r;
    int L, R; cin>>L>>R;

    int newL = max(l, L);
    int newR = min(r, R);
    if(newR >= newL) {
      // overlapping part
      int ans = 0;
      ans += newR - newL;
      if(min(l, L) < newL) {
        ans++;
      }
      if(max(r, R) > newR) {
        ans++;
      }
      cout<<ans<<endl;

    } else {
      // non overlapping
      cout<<1<<endl;
    }
  }
}

signed main() {
  solve();
  return 0;
}
