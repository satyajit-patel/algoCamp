#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>

/*

*/

void solve() {
	int n; cin>>n;
	int a[n];
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}

	for(int i=0; i<n; i++) {
		a[i] = abs(a[i]);
	}

	int ans = *min_element(a, a+n);
	cout<<ans;
}

int main() {
	solve();
	return 0;
}
