#include <bits/stdc++.h>
using namespace std;
#define int long long
// https://codeforces.com/group/yeVhAfeK6s/contest/567616/problem/B
  vector<vector<int>> dp;

 int state(int i, int mask, vector<pair<int, string>>& nums) {
  // base case
  if(mask == 7) {
    return 0;
  }
  if(i >= nums.size()) {
    return 1e9;
  }
  if(dp[i][mask] != -1) {
    return dp[i][mask];
  }

  // transition
  int newMask = mask;
  for(auto& it: nums[i].second) {
    newMask |= (1 << (it - 'A'));
  }
  int take = nums[i].first + state(i+1, newMask, nums);
  int notTake = state(i+1, mask, nums);


  // ans
  int ans = min(take, notTake);
  return dp[i][mask] = ans;
 }

signed main() {
  int n; cin >> n;
  vector<pair<int, string>> nums(n);
  for(int i=0; i<n; i++) {
    int price; cin >> price;
    string vitaminBottle; cin >> vitaminBottle;
    nums[i] = {price, vitaminBottle};
  }

  dp.clear();
  dp.resize(n+1, vector<int>(7+1, -1));
  int ans = state(0, 0, nums);
  if(ans >= 1e9) {
    cout << -1;
    return 0;
  }
  cout << ans;

  return 0;
}