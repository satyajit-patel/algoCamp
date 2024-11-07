#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/2010/C1
void solve() {
	string s; cin >> s;
 
	int n = s.size();
	for(int len=1; len<n; len++) {
		string s1 = s.substr(0, n-len);
		string s2 = s.substr(len);
		if(s1==s2 && len < n-len) {
			cout<<"YES\n"<<s1;
			return;
		}
	}
	cout<<"NO";
} 

int main() {
	solve();
	return 0;
}