#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define vi vector<int> 
#define vvi vector<vector<int>>
// ----------------------------------------------------------
/*
	1
    10
    11
    100
    101
    110
    111
    1000
    1001
    1010
*/

void solve() {
	int n = 10;
	queue<string> q;
	q.push("1");
	while(n--) {
		string binary = q.front();
		cout<<binary<<endl;;
		q.pop();
		q.push(binary + '0');
		q.push(binary + '1');
	}
}

// ----------------------------------------------------------
signed main() {
	solve();
	return 0;
}