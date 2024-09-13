#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define ll long long
// #define int long long
#define vpi vector<pair<int, int>>

void solve() {
	int t; cin>>t;
	while(t--) {
		int n,k; cin>>n>>k;
		string s; cin>>s;

		map<char, int> mp;
		for(auto& it: s) {
			mp[it]++;
		}

		int odd = 0;
		for(auto& it: mp) {
			if(it.second%2) {
				odd++;
			}
		}

		while(k--) {
			for(auto& it: mp) {
				if(it.second % 2) {
					odd--;
					mp[it.first]--;
					break;
				}
			}
		}

		if(odd > 1) {
			cout<<"NO\n";
		} else {
			cout<<"YES\n";
		}
	}
}

signed main() {
	solve();
	return 0;
}
