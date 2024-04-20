#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define ll long long
// #define int long long

void solve() {
	int t; cin>>t;
	while(t--) {
		int n; cin>>n;
		vi a(n);
		for(auto& it: a) {
			cin>>it;
		}

		int totTwos = 0;
		for(auto& it: a) {
			if(it == 2) {
				totTwos++;
			}
		}

		bool ok = false;
		int leftTwo = 0;
		int rightTwo = totTwos;
		for(int k=0; k<n-1; k++) {
			if(a[k] == 2) {
				leftTwo++;
				rightTwo--;
			}

			if(leftTwo == rightTwo) {
				// expecting 1based indexing
				cout<<k+1<<endl;
				ok = true;
				break;
			}
		}
		if(!ok) {
			cout<<"-1\n";
		}
	}
}

signed main() {
	solve();
	return 0;
}
