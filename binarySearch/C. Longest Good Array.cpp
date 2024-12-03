#include <iostream>
using namespace std;

// https://codeforces.com/problemset/problem/2008/C

/*
  let l = 10, r = 20
  10 11 13 16 20

  a1 = l
  a2 = l + 1
  a3 = l + 3
  a4 = l + 6
  a5 = l + 10
  .
  .
  aN => l + (1 + 2 + 3 + ... + N-1)
     // sum of n-1 natural number, so put (n-1) in n(n+1)/2 
     => l + ((n-1)((n-1)+1)/2) <= r
     => n(n-1)/2 = r-l
*/

int main() {
  int t; cin >> t;
  while(t--) {
    int l, r; cin >> l >> r;

    int ans = 0;
    int n = 0;
    int d = r - l;

    while((n * (n-1)/2) <= d) {
      ans = n;
      n++;
    }

    cout << ans << "\n";
  }
  return 0;
}