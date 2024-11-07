#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(2) => iterator at index 2
// order_of_key(2) => index of first occurance of element 2

int mod = 1e9 + 7;
#define endl "\n"
#define int long long
#define vi vector<int>
#define vc vector<char>

// https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/C

bool f(int mid, int n, int x, int y) {
  int xCopies = mid / x;
  int yCopies = mid / y;
  // i.e 
  // in "mid" sec machineX can print xCopies
  // in "mid" sec machineY can print yCopies
  // can they together make required copies at given time
  return xCopies + yCopies >= n;
}

signed main() {
  // fast IO
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // ----------------------------------------------------------------------------
  int n, x, y; cin >> n >> x >> y;

  int ans = -1;
  int i = 0;
  int j = 1e9;
  while(i <= j) {
    int mid = (i + j) / 2;
    if(f(mid, n-1, x, y)) { // we need (n-1) copies, first we will make on our own
      ans = mid;
      // look for mor smaller time
      j = mid - 1;
    } else {
      i = mid + 1;
    }
  }
  cout << ans + min(x, y); // for first copy
  // ----------------------------------------------------------------------------
  return 0;
}

