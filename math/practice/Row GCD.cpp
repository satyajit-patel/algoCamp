#include <bits/stdc++.h>
using namespace std;
#define int long long

// https://codeforces.com/problemset/problem/1458/A

 int getGcd(int a, int b) {
  if(!b) {
    return a;
  }
  return getGcd(b, a % b);
 }

signed main() {
  int n, m; cin >> n >> m;
  int a[n], b[m];
  for(auto& it: a) {
    cin >> it;
  }
  for(auto& it: b) {
    cin >> it;
  }

  // 1 <= n, m <= 1e5
  // 1 <= a[i] <= 1e18

// O(n^2 logn) TLE
//   for(int i=0; i<m; i++) {
//     int gcd = 0;
//     int sum = 0;
//     for(int j=0; j<n; j++) {
//       sum += b[i] + a[j];
//       // cout << gcd << "," << sum;
//       gcd = getGcd(gcd, sum); // O(logn)
//       // cout << " => " << gcd << endl;
//     }
//     cout << gcd << " ";
//     // cout << endl;
//   }

  // calculate the difference first as it will never change
  int d = 0;
  // O(n * logn)
  for(int i=1; i<n; i++) { // O(n)
    int diff = abs(a[i] - a[i-1]);
    d = getGcd(d, diff); // O(logn)
  }
  // now
  int gcd = 0;
  for(int i=0; i<m; i++) {
    gcd = getGcd(b[i] + a[0], d);
    cout << gcd << " ";
  }

  return 0;
}