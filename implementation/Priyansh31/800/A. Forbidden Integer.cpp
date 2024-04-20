#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>

/*

*/

bool state(int n, int k, int x, vi& a) {
	// base case
	if(k < 1) {
		return false;
	}
	if(n < 0) {
		return false;
	}
	if(n == 0) {
		return true;
	}

	// transition
	if(k != x) {
		a.push_back(k);
		if(state(n-k, k, x, a)) {
			return true;
		}
		a.pop_back();
	}
	if(state(n, k-1, x, a)) {
		return true;
	}
	return false;
}

void solve() {
	int t; cin>>t;
	while(t--) {
		int n,k,x; cin>>n>>k>>x;

		vi a;
		if(state(n, k, x, a)) {
			cout<<"YES\n";
			cout<<a.size()<<endl;
			for(auto& it: a) {
				cout<<it<<" ";
			}
			cout<<endl;
		} else {
			cout<<"NO\n";
		}
	}
}

int main() {
	solve();
	return 0;
}
