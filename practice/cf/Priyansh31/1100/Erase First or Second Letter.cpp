#include <bits/stdc++.h>
using namespace std;

int f(string& s, int n) {
  int count = 0;
  unordered_set<char> us;
  for(int i=0; i<n; i++) {
    if(us.find(s[i]) == us.end()) {
      count += ((n-1) - i + 1);
    }
    us.insert(s[i]);
  }
  return count;
}

int main() {
  /*
    1 ≤ n ≤ 1e5 
    https://codeforces.com/problemset/problem/1917/B
  
      ababa -> 9

      ababa | baba |
      abab  | bba  |
      aab   | ba   |
      ab    | b    |
      a     |      |
  */
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    string s; cin >> s;

    cout << f(s, n) << endl;
  }
  return 0;
}