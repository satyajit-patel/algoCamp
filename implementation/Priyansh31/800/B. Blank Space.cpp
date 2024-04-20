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

		int maxAns = 0;
		int i = 0;
		while(i < n) {
			if(a[i] == 0) {
				int j = i;
				while(j < n && a[j] == 0) {
					j++;
				}
				maxAns = max(maxAns, j-i);
				i = j;
			} else {
				i++;
			}
		}
		cout<<maxAns<<endl;
	}
}

int main() {
	solve();
	return 0;
}
