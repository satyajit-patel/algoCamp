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
	string s; cin>>s;

	int maxi = 1;
	int count = 1;
	for(int i=1; i<n; i++) {
		if(s[i] == s[i-1]) {
			count++;
		} else {
			count = 1;
		}
		maxi = max(maxi, count);
	}
	cout<<maxi+1<<endl;
}

signed main() {
	int t = 1; 
	cin>>t;
	while(t--) {
		solve();
	}
	
	return 0;
}
