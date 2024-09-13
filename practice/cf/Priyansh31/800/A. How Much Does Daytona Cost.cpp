#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define vi vector<int>

/*
	1 ≤ n,k ≤ 100

	f(n) = O(n^4)
*/

void solve() {
	int t; cin>>t;
	while(t--) {
		int n,k; cin>>n>>k;
		vi a(n);
		bool found = false;
		for(auto& it: a) {
			cin>>it;
			if(it == k) {
				found = true;
			}
		}
		if(found) {
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
