#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl "\n"
#define vi vector<int> 
#define vvi vector<vector<int>>
// ----------------------------------------------------------
/*
	
*/

void solve() {
	unordered_map<int, set<int>> adj;
	adj[0].insert(1);
	adj[1].insert(0);
	adj[1].insert(2);
	adj[2].insert(1);

	int src = 0;
	int dest = 2;
	int N = 3;
	vector<int> vis(N, 0);
	vector<int> dist(N, 0);
	vector<int> parent(N, -1);

	queue<int> q;
	q.push(src);
	vis[src] = 1;
	while(!q.empty()) {
		int node = q.front();
		q.pop();
		for(auto& child: adj[node]) {
			if(!vis[child]) {
				q.push(child);
				vis[child] = 1;
				dist[child] = dist[node] + 1;
				parent[child] = node;
			}
		}
	}
	cout<<dist[dest];
}

// ----------------------------------------------------------
signed main() {
	solve();
	return 0;
}