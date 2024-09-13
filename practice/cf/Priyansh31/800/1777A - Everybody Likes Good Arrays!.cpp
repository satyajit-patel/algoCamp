#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define ll long long
// #define int long long

bool issame(int a, int b) {
	if(a%2 == 0 && b%2 == 0) {
		return true;
	}
	if(a%2 && b%2) {
		return true;
	}
	return false;
}

void solve() {
	int t; cin>>t;
	while(t--) {
		int n; cin>>n;
		vi a(n);
		for(auto& it: a) {
			cin>>it;
		}

		int ans = 0;
		while(1) {
			bool found = false;
			for(int i=0; i<a.size()-1; i++) {
				if(issame(a[i], a[i+1])) {
					found = true;
					int prod = a[i] * a[i+1];
					a[i] = prod;
					a.erase(a.begin()+i+1);
					ans++;
				}
			}
			if(!found) {
				break;
			}
		}
		cout<<ans<<endl;
	}
}

signed main() {
	solve();
	return 0;
}
