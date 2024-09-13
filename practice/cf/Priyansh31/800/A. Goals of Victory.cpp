#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define vi vector<int>

/*
	1 ≤ n,k ≤ 100

	f(n) = O(n^4)
*/

void solve() {
	int t; cin>>t;
	while(t--) {
		int n; cin>>n;
		vi a(n);
		for(int i=0; i<n-1; i++) {
			cin>>a[i];
		}

		/*
			let n = 4
			a1 + a2 + a3 + a4 = 0(because each time we are adding and substracting)
			a4 = -(a1 + a2 + a3)
		*/
		int sum = accumulate(a.begin(), a.end(), 0);
		int ans = -sum;
		cout<<ans<<endl;	
	}
}

int main() {
	solve();
	return 0;
}
