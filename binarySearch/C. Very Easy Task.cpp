#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl "\n"
#define vi vector<int> 
#define vvi vector<vector<int>>
// ----------------------------------------------------------
/*
	
*/

bool good(int mid, int n, int a, int b) {
	int capacityOfMachine1 = mid/a; 
	int capacityOfMachine2 = mid/b;
	// can both produce needed copies in time
	return (capacityOfMachine1 + capacityOfMachine2) >= n;
}

https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/C
void solve() {
	int n, a, b; cin>>n>>a>>b;

	int ans = -1;
	int lo = 0;
	int hi = max(a, b) * n;
	while(lo <= hi) {
		int mid = (lo + hi) / 2;
		if(good(mid, n-1, a, b)) {
			ans = mid;
			// look for further min candidate
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	// we have to make first original copy
	cout << ans + min(a, b);
}

// ----------------------------------------------------------
signed main() {
	solve();
	return 0;
}