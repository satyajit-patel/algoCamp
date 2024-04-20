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

		/*
			=> a1+b1 <= a2+b2 <= a3+b3
			=> a1+b1 = a2+b2 = a3+b3
		*/
		vi b(n);
		for(int i=0; i<n; i++) {
			b[i] = (n+1) - a[i];
		}

		// for(int i=0; i<n; i++) {
		// 	cout<<a[i]<<" ";
		// }
		// cout<<endl;
		// for(int i=0; i<n; i++) {
		// 	cout<<b[i]<<" ";
		// }
		// cout<<endl;
		// cout<<"-----\n";

		for(auto& it: b) {
			cout<<it<<" ";
		}
		cout<<endl;
	}
}

int main() {
	solve();
	return 0;
}
