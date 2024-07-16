#include<bits/stdc++.h>
using namespace std;
bool isvalid(int i, int j, vector<vector<int>>& grid) {
	int n = grid.size();
	int m = grid[0].size();
	return i>=0 && i<n && j>=0 && j<m;
}
// left leftUp top rightUp right rightDown bottom leftDown
int dx[8] = {0, -1, -1, -1, 0, +1, +1, +1};
int dy[8] = {-1, -1, 0, +1, +1, +1, 0, -1};

// void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis, int& count) {
// 	// cout<<i<<j<<" ";
// 	vis[i][j] = 1;
// 	count++;
// 	for(int ind=0; ind<8; ind++) {
// 		int ni = i + dx[ind];
// 		int nj = j + dy[ind];
// 		if(isvalid(ni, nj, grid) && grid[ni][nj] == 1 && !vis[ni][nj]) {
// 			dfs(ni, nj, grid, vis, count);
// 		}
// 	}
// }

void bfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis, int& count) {
	vis[i][j] = 1;
	queue<pair<int, int>> q;
	q.push({i, j});
	while(!q.empty()) {
		i = q.front().first;
		j = q.front().second;
		q.pop();
		cout<<i<<j<<" ";
		count++;
		for(int ind = 0; ind < 8; ind++) {
			int ni = i + dx[ind];
			int nj = j + dy[ind];
			if(isvalid(ni, nj, grid) && grid[ni][nj] == 1 && !vis[ni][nj]) {
				vis[ni][nj] = 1;
				q.push({ni, nj});
			}
		}
	}
}




void solve() {
    vector<vector<int>> grid = {{1,0,0,1},{1,0,0,0},{1,1,0,1},{0,0,1,0}};
	// vector<vector<int>> grid = {{1,1,1},{1,1,1},{0,1,0}};

	int n = grid.size();
	int m = grid[0].size();
	int ans = 0; 
	vector<vector<int>> vis(n, vector<int>(m, 0));
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(grid[i][j] == 1 && !vis[i][j]) {
				int count = 0;
				// dfs(i, j, grid, vis, count);
				bfs(i, j, grid, vis, count);
				// cout<<endl;
				ans = std::max(ans, count);
			}
		}
	}
	cout<<ans;
}

int main() {
	solve();
	return 0;
}