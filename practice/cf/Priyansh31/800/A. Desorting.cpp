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

		if(is_sorted(a.begin(), a.end())) {
			sort(a.begin(), a.end());
			int minDiff = INT_MAX;
			for(int i=1; i<n; i++) {
				int curDiff = a[i] - a[i-1];
				minDiff = min(minDiff, curDiff);
			}
			int step = (minDiff/2)+1;
			cout<<step<<endl;
		} else {
			cout<<"0\n";
		}
	}
}

int main() {
	solve();
	return 0;
}
