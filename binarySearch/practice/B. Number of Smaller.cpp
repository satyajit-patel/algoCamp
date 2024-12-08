
#include <bits/stdc++.h>
using namespace std;

// CODING IS ALL ABOUT THINKING SLOWLY

int mod = 1e9 + 7;
#define endl "\n"
#define int long long
#define vi vector<int>
#define vc vector<char>

int f(int x, vi& a) {
  int count = 0;
  for(auto& it: a) {
    if(it < x) {
      count++;
    } else {
      break;
    }
  }
  return count;
}

// https://codeforces.com/edu/course/2/lesson/9/1/practice/contest/307092/problem/B

signed main() {
 // fast IO
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 // ------------------------------------------
 int n, m; cin >> n >> m;
 vi a(n), b(m);
 for(auto& it: a) {
  cin >> it;
 }
 for(auto& it: b) {
  cin >> it;
 }

// O(n^2) tle
//  for(auto& it: b) {
//   cout << f(it, a) << " ";
//  }


 // O(n * logn)
 for(auto& it: b) {
  int ind = lower_bound(a.begin(), a.end(), it) - a.begin();
  cout << ind << " ";
 }

 // ------------------------------------------
 return 0;
}




