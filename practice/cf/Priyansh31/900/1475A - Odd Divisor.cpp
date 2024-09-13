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

	if((n&(n-1)) == 0) {
		cout<<"NO\n";
	} else {
		cout<<"YES\n";
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
