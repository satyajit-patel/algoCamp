#include <bits/stdc++.h>
using namespace std;
#define int long long

// https://codeforces.com/problemset/problem/230/B

bool isprime(int n) {
  if(n <= 1) {
    return false;
  }
  for(int i=2; i*i<=n; i++) {
    if(n % i == 0) {
      return false;
    }
  }
  return true;
}

signed main() {
  int n; cin >> n;
  int a[n];
  for(auto& it: a) {
    cin >> it;
  }

  // 1 <= n <= 1e5
  // 1 <= a[i] <= 1e12 

  // O(n * root(n))
  for(auto& it: a) { // O(n)
    int x = sqrt(it);
    if(isprime(x) && x*x == it) { // O(root(n))
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}