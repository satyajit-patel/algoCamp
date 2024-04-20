int dx[4] = {-1, 0, +1, 0}; // URDL
    int dy[4] = {0, +1, 0, -1};

    bool isvalid(int i, int j, auto& grid) {
        return i>=0 && i<grid.size() && j>=0 && j<grid[0].size();
    }

    void bfs(int i, int j, auto& grid, auto& vis) {
        vis[i][j] = 1;
        queue<pair<int, int>> q;
        q.push({i, j});

        while(!q.empty()) {
            i = q.front().first;
            j = q.front().second;
            q.pop();

            for(int ind=0; ind<4; ind++) {
                int ni = i + dx[ind];
                int nj = j + dy[ind];
                if(isvalid(ni, nj, grid) && !vis[ni][nj] && grid[ni][nj] == '1') {
                    vis[ni][nj] = 1;
                    q.push({ni, nj});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int island = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == '1' && !vis[i][j]) {
                    island++;
                    bfs(i, j, grid, vis);
                }
            }
        }

        return island;
    }