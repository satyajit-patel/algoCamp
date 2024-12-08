#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  // 1 <= n <= 1e5
  int a[n];
  for(auto& it: a) {
    cin >> it;
  }

  /*
    https://codeforces.com/problemset/problem/1138/A

    input:
    7
    2 2 2 1 1 2 2

    output: 4

    v
    3 2 2
  */

  int maxi = 0;

  vector<int> v;
  for(int i=0; i<n; i++) {
    if(v.empty() || a[i] != a[i-1]) {
      v.push_back(1);
    } else {
      v.back()++;
    }
  }

  for(int i=1; i<v.size(); i++) {
    maxi = max(maxi, 2 * min(v[i], v[i-1]));
  }

  cout << maxi;

  return 0;
}