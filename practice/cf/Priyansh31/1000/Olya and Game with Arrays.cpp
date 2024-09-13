#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>

void solve() {
  // https://codeforces.com/problemset/problem/1859/B
  int t; cin >> t;
  while(t--) {
    int sum = 0;
    int min1 = INT_MAX;
    int min2 = INT_MAX;
    int hmm; cin >> hmm;
    while(hmm--) {
      int n; cin >> n;
      vi nums(n);
      for(auto& it: nums) cin >> it;

      auto it = min_element(nums.begin(), nums.end());
      int firstMin = *it;
      int ind = it - nums.begin();
      nums.erase(nums.begin() + ind);
      int secondMin = *min_element(nums.begin(), nums.end());
      sum += secondMin;
      min1 = min(min1, firstMin);
      min2 = min(min2, secondMin);
    }
    sum -= min2;
    sum += min1;
    // kyun ki min1 jahan bhi hoga uss array mein vohi add hoga
    // tou jisme kam min2 h uss mein min1 ko rakhen kyun ki hammen
    // sum ko maximize krna h
    cout << sum << endl;
  }
}

signed main() {
  solve();
  return 0;
}
