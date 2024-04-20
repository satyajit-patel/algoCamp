#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>

/*

*/

void solve() {
	int t; cin>>t;
	while(t--) {
		int n; cin>>n;
		vi a(n);
		for(auto& it: a) {
			cin>>it;
		}

		int sum = accumulate(a.begin(), a.end(), 0);
		if(sum%2 == 0) {
			cout<<"YES\n";
		} else {
			cout<<"NO\n";
		}
	}
}

int main() {
	solve();
	return 0;
}
