#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl "\n"
#define vi vector<int> 
#define vvi vector<vector<int>>
// ----------------------------------------------------------
/*
	
*/
vector<int> A;
vector<int> dp;

int state(int sum) {
	// base case
	if(sum <= 0) {
		return 0;
	}
	if(dp[sum] != -1) {
		return dp[sum];
	}

	// transition
	int mini = 1e8;
	for(auto& it: A) {
		if(sum - it < 0) {
			continue;
		}
		mini = min(mini, state(sum - it));
	}
	int ans = 1 + mini;
	dp[sum] = ans;
	return ans;
}

void solve() {
	int n, sum; cin>>n>>sum;
	A.resize(n);
	for(auto& it: A) {
		cin>>it;
	}

	dp.resize(sum+1, -1);
	int ans = state(sum);
	if(ans >= 1e8) {
		cout<<-1;
	} else {
		cout<<ans;
	}
}

// ----------------------------------------------------------
signed main() {
	solve();
	return 0;
}