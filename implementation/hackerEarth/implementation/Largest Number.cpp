#include <bits/stdc++.h>
using namespace std;

// https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/largest-number-10-ca319b09/

void solve() {
	string s; cin>>s;
	int k; cin>>k;

	stack<char> st;
	for(int i=0; i<s.size(); i++) {
		while(!st.empty() && (s[i]-'0')>(st.top()-'0') && k) {
			k--;
			st.pop();
		}
		st.push(s[i]);
	}
	// edge case like 100000 2
	while(k) {
		k--;
		st.pop();
	}

	string ans = "";
	while(!st.empty()) {
		ans += st.top();
		st.pop();
	}
	reverse(ans.begin(), ans.end());
	cout<<ans;
}

int main() {
	solve();
	return 0;
}