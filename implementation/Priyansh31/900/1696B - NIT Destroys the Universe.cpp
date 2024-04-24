#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define ll long long
#define vpi vector<pair<int, int>>

void solve() {
	int n; cin>>n;
	vi a(n);
	for(auto& it: a) {
		cin>>it;
	}

	/*
		we can destroy the contiquitive elements
		postive in just 1 snap like:
		0 1 2 3 4  0
		as we can find 0 as smallest ele for 1 2 3 4 
	*/

	int l = -1;
	int r = -1;
	for(int i=0; i<n; i++) {
		if(a[i] != 0) {
			if(l == -1 && r == -1) {
				l = i;
				r = i;
			} else {
				r = i;
			}
		}
	}

	if(l == -1 && r == -1) {
		// i.e all 0's
		cout<<"0\n";
	} else {
		for(int i=l; i<=r; i++) {
			if(a[i] == 0) {
				// i.e not consiquitive +ve elements
				cout<<"2\n";
				// we we need 2 opr
				// as ist we choose 0 to n-1 and make it +ve
				// then we can make it 0
				return;
			}
		}
		cout<<"1\n";
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
