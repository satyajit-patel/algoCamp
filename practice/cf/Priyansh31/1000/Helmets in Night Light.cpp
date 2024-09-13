#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>

void solve() {
  // https://codeforces.com/problemset/problem/1876/A
  int t; cin>>t;
  while(t--) {
    int n, p; cin >> n >> p;
    vi a(n), b(n);
    for(auto& it: a) {
      cin >> it;
    }
    for(auto& it: b) {
      cin >> it;
    }

    vector<pair<int, int>> nums(n);
    for(int i=0; i<n; i++) {
      nums[i] = {b[i], -a[i]};
    }
    sort(nums.begin(), nums.end());
    // for(auto& it: nums) {
    //   cout << it.first << " " << it.second << "\n";
    // }
    int cost = p; // pak must tell to atleast one
    int residents = 1;
    for(auto& it: nums) {
      int c = it.first;
      int m = -it.second;
      if(c > p) { // usse acha tou pak chanak khud suna dega bc
        break;
      }
      cost += min(m,  n - residents) * c;
      residents += min(m,  n - residents);
    }
    cost += (n - residents) * p;

    cout << cost << endl;
  }
}

signed main() {
  solve();
  return 0;
}
