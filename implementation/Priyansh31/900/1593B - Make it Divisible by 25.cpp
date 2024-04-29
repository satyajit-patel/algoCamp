#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define ll long long
#define vpi vector<pair<int, int>>

int f(string& lastTwoDigit, string& s) {
	char lastDigit = lastTwoDigit[1];
	char secondLastDigit = lastTwoDigit[0];

	int step = 0;

	int j = s.size()-1;
	while(j >= 0 && s[j] != lastDigit) {
		j--;
		step++;
	}

	int i = j-1;
	while(i >= 0 && s[i] != secondLastDigit) {
		i--;
		step++;
	}

	return step;
}

void solve() {
	int n; cin>>n;

	/*
		a num is div by 25 if its last 2 digit is either
		"00", "25", "50" or "75"
	*/

	string s = to_string(n);
	vector<string> div = {"00", "25", "50", "75"};
	int minOps = INT_MAX;
	for(auto& it: div) {
		int curOps = f(it, s);
		minOps = min(minOps, curOps);
	}
	cout<<minOps<<endl;
}

signed main() {
	int t = 1; 
	cin>>t;
	while(t--) {
		solve();
	}
	
	return 0;
}
