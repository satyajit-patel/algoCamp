#include <bits/stdc++.h>
using namespace std;

/*
  https://codeforces.com/contest/2036/problem/C
  input:
  111010
  4
  1 1 => 111010, {},  -3,-2,-1,0
  5 0 => 111000, {1}, 1,2,3,4
  4 1 => 111100, {2}, 0,1,2,3
  5 0 => 111100, {2}, 1,2,3,4

  output:
  NO
  YES
  YES
  YES
*/

void updateSt(int index, set<int>& st, string& s) {
  if(index >= 0 && index+3 < s.size()) {
    if(s.substr(index, 4) == "1100") {
      st.insert(index);
    } else {
      st.erase(index);
    }
  }
}

void solve() {
  string s; cin >> s;
  set<int> st;
  for(int i=0; i<s.size(); i++) { // O(n)
    updateSt(i, st, s);
  }
  int q; cin >> q;
  while(q--) { // O(n)
    int index, value; cin >> index >> value;
    index--;
    s[index] = value + '0';
    for(int i=index-3; i<=index; i++) { // O(1)
      updateSt(i, st, s);
    }
    if(st.size()) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}

int main() {
  int t; cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}