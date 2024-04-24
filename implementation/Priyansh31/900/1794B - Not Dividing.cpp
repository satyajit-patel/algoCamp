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

	for(int i=0; i<n; i++) {
		if(a[i] == 1) {
			a[i] += 1;
		}
	}
	for(int i=1; i<n; i++) {
		if(a[i] % a[i-1] == 0) {
			a[i] += 1;
		}
	}

	for(auto& it: a) {
		cout<<it<<" ";
	}
	cout<<endl;

}

signed main() {
	int t = 1; 
	cin>>t;
	while(t--) {
		solve();
	}
	
	return 0;
}
