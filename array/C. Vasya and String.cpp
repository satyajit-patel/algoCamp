#include <bits/stdc++.h>
using namespace std;
 
// #define int long long
// #define ll long long
#define endl "\n"
#define vi vector<int> 
#define vvi vector<vector<int>>
// ----------------------------------------------------------
/*
	1 <= n <= 1e6
	0 <= k <= n
	2n or 3n == O(n)
*/

int f(string& s, int k, char ch, int n) {
	int ans = INT_MIN;
	int swap_left = 0;
	int i = 0, j = 0;
	while(j < n) {
		while((j < n) && (s[j] == ch)) {
			int window_size = j-i+1;
			ans = max(ans, window_size);
			j++;
		}
		while((j < n) && (s[j] != ch) && (swap_left < k)) {
			swap_left++;
			int window_size = j-i+1;
			ans = max(ans, window_size);
			j++;
		}
		while((i <= j) && (s[j] != ch) && (swap_left >= k)) {
			swap_left -= (s[i] != ch);
			i++;
		}
	}
	return ans;
}

void solve() {
	int n, k; cin>>n>>k;
	string s; cin>>s;
	int a = f(s, k, 'a', n);
	int b = f(s, k, 'b', n);
	cout<<max(a, b);
}
// ----------------------------------------------------------
signed main() {
	solve();
	return 0;
}