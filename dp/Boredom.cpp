#include <bits/stdc++.h>
using namespace std;
#define int long long

// https://codeforces.com/contest/455/problem/A

// dp
// 1. define state / subproblem
// 2. define base case
// 3. define transition / formula
// 4. define ans

map<int, int> freq;
vector<int> dp;

long long state(int maxi) { // only consider till "i", and discard ele more than "i"
  // base case
  if(maxi == 0) {
    return 0;
  }
  if(maxi == 1) {
    return freq[1];
  }
  if(dp[maxi] != -1) {
    return dp[maxi];
  }

  // transition
  int take = maxi * freq[maxi] + state(maxi-2); // as num-1 will be gone
  int notTake = state(maxi-1);

  // ans
  int ans = max(take, notTake);
  return dp[maxi] = ans;
}

signed main() {
  int n; cin >> n;
  vector<int> nums(n);
  for(int i=0; i<n; i++) {
    cin >> nums[i];
  }
  // 1 <= n <= 1e5
  // 1 <= a[i] <= 1e5
  // as the contraints are high.. so it's giving sign to use num itself

  freq.clear();
  for(auto& it: nums) {
    freq[it]++;
  }
  int maxi = *max_element(nums.begin(), nums.end());
  dp.clear();
  dp.resize(maxi+1, -1);
  int ans = state(maxi);
  cout << ans;

  return 0;
}
