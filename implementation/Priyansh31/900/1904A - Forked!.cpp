#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define ll long long
// #define int long long
#define vpi vector<pair<int, int>>

void solve() {
	int t; cin>>t;
	while(t--) {
		int x,y; cin>>x>>y;
		int xk,yk; cin>>xk>>yk;
		int xq,yq; cin>>xq>>yq;
							
		/*					-x		x
						-------- --------
			  y	|				|y				 |y
				|		-x		|		x		 |
				|------------- King -------------|
				|				|				 |
			 -y	|				|-y				 |-y
						-------- --------
						-x				x

				there are 8 way a Knight can attack the King
				so we have to find 
				the number of common position of Knight
				from where it can attack both King and Queen;
		*/

		vpi dir = {{x,y}, {x, -y}, {-x, y}, {-x, -y}, 
				   {y,x}, {y,-x}, {-y,x}, {-y,-x}};

		set<pair<int, int>> st1, st2;
		for(auto& it: dir) {
			int ni1 = xk + it.first;
			int nj1 = yk + it.second;

			int ni2 = xq + it.first;
			int nj2 = yq + it.second;

			st1.insert({ni1, nj1});
			st2.insert({ni2, nj2});
		}

		int ans = 0;
		for(auto& it: st1) {
			if(st2.find({it.first, it.second}) != st2.end()) {
				ans++;
			}
		}
		cout<<ans<<endl;
	}
}

signed main() {
	solve();
	return 0;
}
