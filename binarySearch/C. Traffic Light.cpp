#include <bits/stdc++.h>
using namespace std;

// CODING IS ALL ABOUT THINKING SLOWLY

int mod = 1e9 + 7;
#define endl "\n"
#define int long long
#define vi vector<int>
#define vc vector<char>

/*
  input:
    // 1 <= n <= 1e5
    5 r
    rggry
  output: 
    3

  https://codeforces.com/problemset/problem/1744/C
*/

signed main() {
 // fast IO
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 // ------------------------------------------
 int t; cin >> t;
 while(t--) {
  int n; cin >> n;
  char c; cin >> c;
  string s; cin >> s;

  int maxDist = INT_MIN; 

  vi pos;
  for(int i=0; i<n; i++) {
    if(s[i] == c) {
      pos.push_back(i);
    }
  }

  s += s;

// TLE
//   for(auto& it: pos) {
//     for(int i=it; i<s.size(); i++) {
//       if(s[i] == 'g') {
//         int curDist = i - it;
//         maxDist = max(maxDist, curDist);
//         break;
//       }
//     }
//   }

  set<int> greenPos;
  for(int i=0; i<s.size(); i++) {
    if(s[i] == 'g') {
      greenPos.insert(i);
    }
  }

  for(auto& it: pos) { // O(#c)
    int curDist = (*greenPos.lower_bound(it)) - it; // O(log #g)
    maxDist = max(maxDist, curDist);
  }

  cout << maxDist << endl; 
 }
 // ------------------------------------------
 return 0;
}

		// or

#include <bits/stdc++.h>
using namespace std;

// CODING IS ALL ABOUT THINKING SLOWLY

int mod = 1e9 + 7;
#define endl "\n"
#define int long long
#define vi vector<int>
#define vc vector<char>

/*
  input:
    // 1 <= n <= 1e5
    5 r
    rggry
  output: 
    3

  https://codeforces.com/problemset/problem/1744/C
*/

signed main() {
 // fast IO
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 // ------------------------------------------
 int t; cin >> t;
 while(t--) {
  int n; cin >> n;
  char c; cin >> c;
  string s; cin >> s;

  int maxDist = INT_MIN; 

  s += s;

  int lastGreen = -1;
  for(int i=s.size()-1; i>=0; i--) { // O(n)
    if(s[i] == 'g') {
      lastGreen = i;
    }
    if(s[i] == c) {
      maxDist = max(maxDist, lastGreen - i);
    }
  }

  cout << maxDist << endl; 
 }
 // ------------------------------------------
 return 0;
}









