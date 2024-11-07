#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(2) => an iterator pointing to element 2
// order_of_key(2)  => an index pointing to element 2
// CODING IS ALL ABOUT THINKING SLOWLY, BUT CODING FAST

int mod = 1e9 + 7;
#define endl "\n"
#define int long long
#define vi vector<int>
#define vc vector<char>

// https://codeforces.com/problemset/problem/2024/B
int f(vi& a, int k) {
  std::sort(a.begin(), a.end());
  int pressCount = k;
  int sub = 0;
  int n = a.size();
  for(int i=0; i<n; i++) {
    a[i] -= sub;
    k -= min(k, a[i] * (n-i));
    if(k == 0) {
      break;
    } else {
      pressCount++;
    }
    sub += a[i];
  }
  return pressCount;
}

signed main() {
  // fast IO
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // ----------------------------------------------------------------------------
  int t; cin >> t;
  while(t--) {
    int n, k; cin >> n >> k;
    vi a(n);
    for(auto& it: a) {
      cin >> it;
    }

    int ans = f(a, k);
    cout << ans << endl;
  }
  // ----------------------------------------------------------------------------
  return 0;
}

