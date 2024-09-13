#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>

int state(int i, int n, int m, vi& arr, vvi& dp) {
	// base case
	if(n < 0) {
		return 0;
	}
	if(i >= m) {
		return 0;
	}
	if(dp[i][n] != -1) {
		return dp[i][n];
	}

	// transition
	int take = 0;
	if(n-arr[i] >= 0) {
		take = 1 + state(i+1, n-arr[i], m, arr, dp);
	}
	int notTake = state(i+1, n, m, arr, dp);
	int ans = max(take, notTake);
	dp[i][n] = ans;
	return ans;
}

int main() {
	int t; cin>>t;
	while(t--) {
		int n,m; cin>>n>>m;
		vi arr(m);
		for(auto& it: arr) {
			cin>>it;
		}

		// ac
		sort(arr.begin(), arr.end());
		int ans = 0;
		for(auto& it: arr) {
			if(n-it >= 0) {
				n -= it;
				ans++;
			} else {
				break;
			}
		}

		// // we can't use dp as n*m > 10^8
		// // it will be MLE
		// vvi dp(m+1, vi(n+1, -1));
		// int ans = state(0, n, m, arr, dp);

		cout<<ans<<endl;
	}
}