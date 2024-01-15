#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl "\n"
#define vi vector<int> 
#define vvi vector<vector<int>>
// ----------------------------------------------------------
/*
	first non repeating character
	input -> abacab
	output-> aabbbc
	i.e
	  string    output	  queue
		a		-> a		a
		ab		-> b		ab
		aba		-> b    	b
		abac	-> b		bc
		abaca	-> b		bc
		abacab	-> c		c
*/

void solve() {
	string s = "abba";

	queue<char> q;
	map<char, int> map;
	string ans = "";
	for(int i=0; i<s.size(); i++) {
		if(!map.count(s[i])) {
			q.push(s[i]);
		}
		map[s[i]]++;
		while(!map.empty() && map[q.front()] > 1) {
			q.pop();
		}
		if(q.empty()) {
			ans += "-1";
		} else {
			ans += q.front();
		}
		// queue<char> temp = q;
		// while(!temp.empty()) {
		// 	cout<<temp.front()<<" ";
		// 	temp.pop();
		// }
		// cout<<endl;
	}
	cout<<endl<<ans<<endl;
}

// ----------------------------------------------------------
signed main() {
	solve();
	return 0;
}