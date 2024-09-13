#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define ll long long
#define vpi vector<pair<int, int>>

void solve() {
	int n; cin>>n;

	/*
		to make it 1
		the num must contain 2^x and 3^x as prime factorization

		3
			2^0 * 3^1
			2^1 * 3^1 => one operation
			6/6 = 1   => one operation
			total     => 2 operation needed to make it 1
	*/

	int count_2 = 0;
	while(n % 2 == 0) {
		count_2++;
		n /= 2;
	}

	int count_3 = 0;
	while(n % 3 == 0) {
		count_3++;
		n /= 3;
	}

	if(n != 1) {
		cout<<"-1\n";
		return;
	}
	if(count_2 <= count_3) {
		cout<<(count_3 - count_2) + count_3<<endl;
	} else {
		cout<<"-1\n";
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
