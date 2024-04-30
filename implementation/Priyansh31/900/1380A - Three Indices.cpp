#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpi vector<pair<int, int>>


void solve() {
	int n; cin>>n;
	vi a(n);
	for(auto& it: a) {
		cin>>it;
	}

	// for(int i=1; i<n-1; i++) {
	// 	if(a[i] > a[i-1] && a[i] > a[i+1]) {
	// 		cout<<"YES\n";
	// 		// expecting 1 based indexing
	// 		cout<<i-1 +1<<" "<<i +1<<" "<<i+1 +1<<endl;
	// 		return;
	// 	}
	// }
	// cout<<"NO\n";


	// or

	vi minLeft(n), minRight(n);
	int mini = INT_MAX;
	for(int i=0; i<n; i++) {
		if(a[i] < mini) {
			mini = a[i];
			minLeft[i] = i;
		} else {
			minLeft[i] = minLeft[i-1];
		}
	}
	mini = INT_MAX;
	for(int i=n-1; i>=0; i--) {
		if(a[i] < mini) {
			mini = a[i];
			minRight[i] = i;
		} else {
			minRight[i] = minRight[i+1];
		}
	}

	for(int i=1; i<n-1; i++) {
		if(a[i] > a[minLeft[i-1]] && a[i] > a[minRight[i+1]]) {
			cout<<"YES\n";
			// expecting 1 based indexing
			cout<<minLeft[i-1] +1<<" "<<i +1<<" "<<minRight[i+1] +1<<endl;
			return;
		}
	}
	cout<<"NO\n";
}

signed main() {
	int t = 1; 
	cin>>t;
	while(t--) {
		solve();
	}
	
	return 0;
}
