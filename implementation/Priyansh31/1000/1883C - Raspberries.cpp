#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpi vector<pair<int, int>>

int f(vi& a, int n, int k) {
	int d = INT_MAX;
	int numEvenEle = 0;
	for(int i=0; i<n; i++) {
		if(a[i]%k == 0) {
			d = 0;
		} else {
			d = min(d, k-(a[i]%k));
		}
		if(a[i]%2 == 0) {
			numEvenEle++;
		}
	}
	if(k != 4) {
		return d;
	} else {
		if(numEvenEle >= 2) {
			return 0;
		} else if(numEvenEle == 1) {
			return min(1, d);
		} else {
			return min(2, d);
		}
	}
}

void solve() {
	int n, k; cin>>n>>k;
	vi a(n);
	for(auto& it: a) {
		cin>>it;
	}

	cout<<f(a, n, k)<<endl;
}

signed main() {
	int t = 1; 
	cin>>t;
	while(t--) {
		solve();
	}
	
	return 0;
}
