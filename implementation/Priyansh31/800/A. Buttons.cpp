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
		int a,b,c; cin>>a>>b>>c;

		if(c%2 == 0) {
			int half = c/2;
			a += half;
			b += half;
		} else {
			int half = c/2;
			a += (half + 1);
			b += half;
		}

		if(a > b) {
			cout<<"First\n";
		} else {
			cout<<"Second\n";
		}
	}
}

int main() {
	solve();
	return 0;
}
