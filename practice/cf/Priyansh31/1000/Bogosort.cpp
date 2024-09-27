#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/problemset/problem/1312/B

void solve() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) {
      cin >> a[i];
    }
    /*
      5 6 4
      __0_____1____2____3____4____5__
      | +6 | +5 | +4 | +3 | +2 | +1 |
      _______________________________
      | -6 | -4 | -2 | +0 | +2 | +4 |
      _______________________________
    */

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    map<int, int> mp;
    for(int i=0; i<n; i++) {
      int x = i - a[i];
      auto it = mp.find(x);
      if(it != mp.end()) {
        std::swap(a[i], a[mp[x]]);
        mp.erase(it);
      }

      mp[x] = i;
    }
    for(auto& it: a) {
      cout << it << " ";
    }
    cout << endl;
  }
}

int main() {
  solve();
  return 0;
}