/*
        Constraints:
        m == grid.length
        n == grid[i].length
        1 <= m, n <= 15
        0 <= grid[i][j] <= 100
        There are at most 25 cells containing gold.

        Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
        Output: 24
        Explanation:
        [[0,6,0],
        [5,8,7],
        [0,9,0]]
        Path to get the maximum gold, 9 -> 8 -> 7.
    */

    bool isvalid(int i, int j, int n, int m) {
        return i>=0 && i<n && j>=0 && j<m;
    }

    int state(int i, int j, auto& grid, int n, int m) {
        // base case
        if(!isvalid(i, j, n, m)) {
            return 0;
        }
        if(grid[i][j] == 0) {
            return 0;
        }
        if(grid[i][j] == -1) {
            return 0;
        }

        // transition
        int data = grid[i][j];
        grid[i][j] = -1;
        int left = state(i, j-1, grid, n, m);
        int up = state(i-1, j, grid, n, m);
        int right = state(i, j+1, grid, n, m);
        int down = state(i+1, j, grid, n, m);
        grid[i][j] = data; // backtrack
        int ans = data + max({left, up, right, down});
        // // debug
        // cout<<left<<up<<right<<down<<ans<<"->";
        return ans;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int maxi = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] != 0) {
                    int ans = state(i, j, grid, n, m);
                    maxi = max(maxi, ans);
                }
            }
        }
        return maxi;
    }