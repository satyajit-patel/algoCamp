#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define ll long long
#define int long long
#define vpi vector<pair<int, int>>

/*
	1 <= n,k <= 10^5
	1 <= x <= 10^10 // need long long here
*/

void solve() {
	int n,k,x; cin>>n>>k>>x;

	int low = 0;
	int high = 0;

	// // TLE
	// for(int i=1, j=0; i<=n && j<k; i++, j++) {
	// 	low += i;
	// }
	// for(int i=n, j=0; i>=1 && j<k; i--, j++) {
	// 	high += i;
	// }

	// sum of "n" natural number
	low = (k*(k+1))/2;

	int total = (n*(n+1))/2;
	int temp = n - k;
	int restPart = (temp*(temp+1))/2;

	high = total - restPart; 


	// cout<<low<<"->"<<high<<endl;

	if(x < low || x > high) {
		cout<<"NO\n";
	} else {
		cout<<"YES\n";
	}
}

signed main() {
	int t = 1; 
	cin>>t;
	while(t--) {
		solve();
	}
	
	return 0;
}
