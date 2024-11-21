#include <bits/stdc++.h>
using namespace std;

// CODING IS ALL ABOUT THINKING SLOWLY, BUT CODING FAST

const int mod = 1e9 + 7;
#define endl "\n"
// #define int long long
#define vi vector<int>
#define vc vector<char>

bool good(int mid, int k, int l, int r) {
//   int count = 0;
//   for(int i=l; i<=r; i++) {
//     if(i % mid == 0) {
//       count++;
//     }
//     if(count >= k) {
//       return true;
//     }
//   }
//   return false;

  // mid * x <= r
  int x = r / mid;
  return x >= k;
}

signed main() {
  // fast IO
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // ----------------------------------------------------------------------------
  // https://codeforces.com/contest/2029/problem/A
  int t; cin >> t;
  while(t--) {
    int l, r, k; cin >> l >> r >> k;
    // 1 <= r <= 1e9
    // 3 4 5 6 7 8 9, k = 2 now finding which num can be last deleted
    // Y Y N N N N N
    int ans = -1;
    int i = l;
    int j = r;
    while(i <= j) {
      int mid = (i + j) / 2;
      if(good(mid, k, l, r)) {
        ans = mid;
        i = mid + 1;
        // cout << ans << endl;
      } else {
        j = mid - 1;
      }
    }
    cout << max(ans-l+1, 0) << endl;
  }
  // ----------------------------------------------------------------------------
  return 0;
}




		// or






#include <bits/stdc++.h>
using namespace std;

// CODING IS ALL ABOUT THINKING SLOWLY, BUT CODING FAST

const int mod = 1e9 + 7;
#define endl "\n"
#define int long long
#define vi vector<int>
#define vc vector<char>

signed main() {
  // fast IO
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // ----------------------------------------------------------------------------
  // https://codeforces.com/contest/2029/problem/A
  int t; cin >> t;
  while(t--) {
    int l, r, k; cin >> l >> r >> k;
    // 1 <= r <= 1e9

    // x*k <= r
    int ans = (r/k)-l+1;
    if(ans < 0) {
      ans = 0;
    }
    cout << ans << endl;
  }
  // ----------------------------------------------------------------------------
  return 0;
}

