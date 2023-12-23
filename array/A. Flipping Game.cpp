#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl "\n"
#define vi vector<int> 
#define vvi vector<vector<int>>
// ----------------------------------------------------------
/*
	
*/

void solve() {
	int n; cin>>n;
	vi A(n);
	for(auto& it: A) {
		cin>>it;
	}

	// kadane
	int count_one = 0;
	int sum = 0;
	int maxSum = INT_MIN;
	for(int i=0; i<n; i++) {
		if(A[i] == 1) {
			sum--;
			count_one++;
		}
		else {
			sum++;
		}
		maxSum = max(maxSum, sum);

		if(sum < 0) {
			sum = 0;
		}
	}
	cout<<maxSum + count_one;
}

// ----------------------------------------------------------
signed main() {
	solve();
	return 0;
}