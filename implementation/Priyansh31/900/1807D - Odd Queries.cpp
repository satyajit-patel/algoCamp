#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define ll long long
#define vpi vector<pair<int, int>>

void solve() {
	int n,q; cin>>n>>q;
	vi a(n);
	for(auto& it: a) {
		cin>>it;
	}

	// // TLE
	// while(q--) {
	// 	int l,r,k; cin>>l>>r>>k;
	// 	vi temp = a;
	// 	for(int i=l-1; i<r; i++) {
	// 		temp[i] = k;
	// 	}
	// 	int totSum = 0;
	// 	for(auto& it: temp) {
	// 		totSum += it;
	// 		// cout<<it<<" ";
	// 	}
	// 	// cout<<endl;
	// 	// cout<<totSum<<endl;
	// 	if(totSum&1) {
	// 		cout<<"YES\n";
	// 	} else {
	// 		cout<<"NO\n";
	// 	}
	// }

	vi prefixSum(n, 0), suffixSum(n, 0);
	int sum = 0;
	for(int i=0; i<n; i++) {
		sum += a[i];
		prefixSum[i] = sum;
	}
	sum = 0;
	for(int i=n-1; i>=0; i--) {
		sum += a[i];
		suffixSum[i] = sum;
	}

	while(q--) {
		int l,r,k; cin>>l>>r>>k;
		// make it 0based indexing
		l--;
		r--;
		
		int curSum = k * (r-l+1);
		if(l > 0) {
			// cout<<"ok l->";
			curSum += prefixSum[l-1];
		}
		if(r < n-1) {
			// cout<<"ok r->";
			curSum += suffixSum[r+1];
		}
		// cout<<curSum<<" "<<l<<"->"<<r<<endl;

		if(curSum&1) {
			cout<<"YES\n";
		} else {
			cout<<"NO\n";
		}
	}
}

signed main() {
	int t = 1; 
	cin>>t;
	while(t--) {
		solve();
	}
	
	return 0;
}
