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

		vi b, c;
		/*
			for sa "a" is divisor of "b" => 
			"a" sould be less than equal to b
		*/

		sort(a.begin(), a.end());
		if(a[0] == a[n-1]) {
			cout<<"-1\n";
		} else {
			int init = 0;
			while(a[init] == a[0]) {
				init++;
			}
			for(int i=0; i<init; i++) {
				b.push_back(a[i]);
			}
			for(int i=init; i<n; i++) {
				c.push_back(a[i]);
			}

			cout<<init<<" "<<n-init<<endl;
			for(auto& it: b) {
				cout<<it<<" ";
			}
			cout<<endl;
			for(auto& it: c) {
				cout<<it<<" ";
			}
			cout<<endl;
		}
	}
}

int main() {
	solve();
	return 0;
}
