#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpi vector<pair<int, int>>

int f(string& s) {
	int num_one = 0, num_zero = 0;
	for(auto& it: s) {
		if(it == '1') {
			num_one++;
		} else {
			num_zero++;
		}
	}
	for(int i=0; i<s.size(); i++) {
		if(s[i] == '1') {
			if(num_zero) {
				num_zero--;
			} else {
				return s.size() - i;
			}
		} else {
			if(num_one) {
				num_one--;
			} else {
				return s.size() - i;
			}
		}
	}
	return 0;
}

void solve() {
	string s; cin>>s;

	cout<<f(s)<<endl;
}

signed main() {
	int t = 1; 
	cin>>t;
	while(t--) {
		solve();
	}
	
	return 0;
}
