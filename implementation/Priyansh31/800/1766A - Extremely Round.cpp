#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define ll long long
// #define int long long

set<int> st;

bool good(int n) {
	int count = 0;
	while(n) {
		int lastEle = n % 10;
		n /= 10;
		if(lastEle != 0) {
			count++;
		}

		// save time
		if(count > 1) {
			return false;
		}
	}
	return count == 1;
}

void solve() {
	// pre-compute
	for(int i=0; i<1e7; i++) {
		if(good(i)) {
			st.insert(i);
		}
	} 

	int t; cin>>t;
	while(t--) {
		int n; cin>>n;

		/*
			patterns
			1digit 1 - 9 = 9
			2digit 10 - 99 = 9
			3digit 100 - 999 = 9
			4digit 1e4 - 1e5-1 = 9
			.
			.
			.
			6digit 1e6 - 1e7-1 = 9
		*/
		int ans = 0;
		for(auto& it: st) {
			if(it <= n) {
				ans++;
			}
		}
		cout<<ans<<endl;
	}
}

signed main() {
	solve();
	return 0;
}
