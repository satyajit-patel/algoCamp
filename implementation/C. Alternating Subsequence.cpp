#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl "\n"
#define vi vector<int> 
#define vvi vector<vector<int>>
// ----------------------------------------------------------
/*
	
*/

bool sign(int num) {
	return num > 0;
}

void solve() {
	int tc; cin>>tc;
	while(tc--) {
		int n; cin>>n;
		vi A(n);
		for(auto& it: A) {
			cin>>it;
		}

		int ans = 0;
		for(int i=0; i<n; i++) {
			int j = i;
			int maxi = A[i];
			while(j<n && sign(A[i]) == sign(A[j])) {
				maxi = max(maxi, A[j]);
				j++;
			}
			ans += maxi;
			i = j-1;
		}
		cout<<ans<<endl;
	}
}

// ----------------------------------------------------------
signed main() {
	solve();
	return 0;
}