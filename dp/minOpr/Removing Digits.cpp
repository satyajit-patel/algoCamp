#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl "\n"
#define vi vector<int> 
#define vvi vector<vector<int>>
// ----------------------------------------------------------
/*
	
*/

vector<int> dp;

int state(int n) {
	// base case
	if(n < 0) {
		return 1e8;
	}
	if(n == 0) {
		return 0;
	}
	if(dp[n] != -1) {
		return dp[n];
	}

	// transition
	int mini = INT_MAX;
	string s = to_string(n);
	for(auto& it: s) {
		int num = it - '0';
		if(num == 0) {
			continue;
		}
		mini = min(mini, state(n-num));
	}
	int ans = 1 + mini;
	dp[n] = ans;
	return ans;
}

void solve() {
	int n; cin>>n;

	dp.resize(n+1, -1);
	int ans = state(n);
	cout<<ans;
}

// ----------------------------------------------------------
signed main() {
	solve();
	return 0;
}