#include <bits/stdc++.h>
using namespace std;

// https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/asme-to-same-3-3e7c0c0d/

void solve() {
	int n; cin>>n;
	string s, t; cin>>s>>t;

	string ans = "Yes";
	for(auto& it: s) {
		if(it == '?') {
			continue;
		}
		int index = t.find(it);
		if(index != -1) {
			t.erase(t.begin()+index);
		} else {
			ans = "No";
			break;
		}
	}
	cout<<ans<<endl;
}

int main() {
	int tc; cin>>tc;
	while(tc--) {
		solve();
	}
	return 0;
}