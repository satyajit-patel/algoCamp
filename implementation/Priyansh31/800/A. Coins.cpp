#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define ll long long

/*
	(1 ≤ k ≤n ≤ 10^18; k≠2)
	so we need long long here
*/



void solve() {
	int t; cin>>t;
	while(t--) {
		ll n,k; cin>>n>>k;

		/*
			2*x + k*y = n
			so can we represent "n" with (2x) + (k*y)
			just obsevation

			if n is even
				generally we represent even num as (2*x)
				so just put
				y = 0
				x = n/2
			if n is odd
				put y = 1
				generally we represent even num as 
				=> (2*x) + 1
					or
				=> (2*x) + k
					so k need to be a odd number
				like 
					5 = (2*2) + 1
					7 = (2*3) + 1 or (2*2) + 3
		*/
		if(n%2 == 0) {
			cout<<"YES\n";
		} else {
			if(k%2) {
				cout<<"YES\n";
			} else {
				cout<<"NO\n";
			}
		}
	}
}

int main() {
	solve();
	return 0;
}
