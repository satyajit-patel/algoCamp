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

		int pos = 0;
		int neg = 0;
		for(auto& it: a) {
			if(it == 1) {
				pos++;
			} else {
				neg++;
			}
		}
		int ans = 0;
		while(!(pos >= neg && neg%2 == 0)) {
			ans++;
			pos++;
			neg--;
		}
		cout<<ans<<endl;
	}
}

int main() {
	solve();
	return 0;
}
