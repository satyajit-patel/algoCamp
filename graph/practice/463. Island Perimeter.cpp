/*
        Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
        Output: 16
        Explanation: 
        The perimeter is the 16 yellow stripes in the image above.
    */

    int dx[4] = {-1, 0, +1, 0}; // URDL
    int dy[4] = {0, +1, 0, -1};

    bool isvalid(int i, int j, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        return i>=0 && i<n && j>=0 && j<m;
    }

    int bfs(int i, int j, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vis[i][j] = 1;
        queue<pair<int, int>> q;
        q.push({i, j});

        int perimeter = 0;
        while(!q.empty()) {
            i = q.front().first;
            j = q.front().second;
            q.pop();

            // up
            if(!isvalid(i-1, j, grid) || grid[i-1][j] == 0) {
                perimeter++;
            }
            // right
            if(!isvalid(i, j+1, grid) || grid[i][j+1] == 0) {
                perimeter++;
            }
            // bottom
            if(!isvalid(i+1, j, grid) || grid[i+1][j] == 0) {
                perimeter++;
            }
            // left
            if(!isvalid(i, j-1, grid) || grid[i][j-1] == 0) {
                perimeter++;
            }

            for(int ind=0; ind<4; ind++) {
                int ni = i + dx[ind];
                int nj = j + dy[ind];
                if(isvalid(ni, nj, grid) && grid[ni][nj] == 1 && !vis[ni][nj]) {
                    vis[ni][nj] = 1;
                    q.push({ni, nj});
                }
            }
        }
        return perimeter;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) {
                    // there is only one island present as menstioned
                    ans = bfs(i, j, grid);
                    break;
                }
            }
        }
        return ans;
    }