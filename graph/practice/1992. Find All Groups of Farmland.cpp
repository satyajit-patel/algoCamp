void bfs(int i, int j, auto& vis, auto& land, auto& groups) {
        int n = land.size();
        int m = land[0].size();
        vis[i][j] = 1;
        queue<pair<int, int>> q;
        q.push({i, j});

        // URDL
        vector<pair<int, int>> dir = {{-1,0}, {0, +1}, {+1, 0}, {0, -1}}; 
        // int dx[4] = {-1, 0, +1, 0};
        // int dy[4] = {0, +1, 0, -1};

        vector<pair<int, int>> temp;
        while(!q.empty()) {
            i = q.front().first;
            j = q.front().second;
            q.pop();

            temp.push_back({i, j});

            for(auto& it: dir) {
                int ni = i + it.first;
                int nj = j + it.second;
                if(ni>=0 && ni<n && nj>=0 && nj<m) {
                    if(land[ni][nj] == 1 && !vis[ni][nj]) {
                        vis[ni][nj] = 1;
                        q.push({ni, nj});
                    }
                }
            }

            // for(int ind=0; ind<4; ind++) {
            //     int ni = i + dx[ind];
            //     int nj = j + dy[ind];
            //     if(ni>=0 && ni<n && nj>=0 && nj<m) {
            //         if(land[ni][nj] == 1 && !vis[ni][nj]) {
            //             vis[ni][nj] = 1;
            //             q.push({ni, nj});
            //         }
            //     }
            // }
        }

        groups.push_back(temp);
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<pair<int, int>>> groups;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(land[i][j] == 1 && !vis[i][j]) {
                    bfs(i, j, vis, land, groups);
                }
            }
        }

        vector<vector<int>> ans;
        for(auto& row: groups) {
            vector<pair<int, int>> temp = row;
            int min1 = INT_MAX, min2 = INT_MAX;
            int max1 = INT_MIN, max2 = INT_MIN;
            for(auto& it: temp) {
                int x = it.first;
                int y = it.second;
                if(x <= min1 && y <= min2) {
                    min1 = x;
                    min2 = y;
                }
                if(x >= max1 && y >= max2) {
                    max1 = x;
                    max2 = y;
                }
            }
            ans.push_back({min1, min2, max1, max2});
        }
        return ans;
    }