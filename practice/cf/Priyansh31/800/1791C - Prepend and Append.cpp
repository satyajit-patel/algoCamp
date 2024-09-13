#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define ll long long

void solve() {
	int t; cin>>t;
	while(t--) {
		int n; cin>>n;
		string s; cin>>s;

		int i = 0;
		int j = n-1;
		while(i < j) {
			if(s[i] != s[j]) {
				i++;
				j--;
			} else {
				break;
			}
		}
		cout<<j-i+1<<endl;
	}
}

int main() {
	solve();
	return 0;
}
