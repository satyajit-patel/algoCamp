#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  string s; cin >> s;

  for(int i=0; i<n-1; i++) {
    /*
      1 <= n <= 1e5
      https://codeforces.com/problemset/problem/1155/A
      ____________________________________
      |don't fall in given test case trap|
      |always focus on smallest testcase |
      |-----------------------------------
    */
    if(s[i] > s[i+1]) {
      cout << "YES \n";
      cout << i+1 << " " << i+1+1; // 1 based indexing
      return;
    }
  }
  cout << "NO";
}

int main() {
  solve();
  return 0;
}