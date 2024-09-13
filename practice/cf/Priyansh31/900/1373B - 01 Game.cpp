#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define ll long long
#define vpi vector<pair<int, int>>

void solve() {
	string s; cin>>s;

	int num_zero = 0;
	for(auto& it: s) {
		if(it == '0') {
			num_zero++;
		}
	}
	int num_one = s.size() - num_zero;

	int totalMove = min(num_zero, num_one);
	if(totalMove % 2) {
		cout<<"DA\n";
	} else {
		cout<<"NET\n";
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
