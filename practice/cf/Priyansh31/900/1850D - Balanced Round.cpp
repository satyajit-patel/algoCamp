#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define ll long long
#define vpi vector<pair<int, int>>

void solve() {
	int n,k; cin>>n>>k;
	vi a(n);
	for(auto& it: a) {
		cin>>it;
	}

	// as there is atleast 1 element
	int count = 1;
	int maxConsiquitiveEle = count;

	sort(a.begin(), a.end());

	for(int i=1; i<n; i++) {
		if(a[i]-a[i-1] <= k) {
			count++;
		} else {
			count = 1;
		}
		maxConsiquitiveEle = max(maxConsiquitiveEle, count);
	}
	cout<<n-maxConsiquitiveEle<<endl;
}

signed main() {
	int t = 1; 
	cin>>t;
	while(t--) {
		solve();
	}
	
	return 0;
}
