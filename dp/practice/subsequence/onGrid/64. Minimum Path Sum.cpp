/*
        Example 1:
        Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
        Output: 7
        Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

        Constraints:
        m == grid.length
        n == grid[i].length
        1 <= m, n <= 200
        0 <= grid[i][j] <= 200

        expected f(n) = O(n^4)
        our f(n) = O(2^n) with recursion, O(n) with dp
    */

    int state(int i, int j, auto& grid, int n, int m, auto& dp) {
        // base case
        if(i==grid.size()-1 && j==grid[0].size()-1) {
            return grid[i][j];
        }
        if(i == n) {
            return 1e8;
        }
        if(j == m) {
            return 1e8;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        // transition
        int down = grid[i][j] + state(i+1, j, grid, n, m, dp);
        int right = grid[i][j] + state(i, j+1, grid, n, m, dp);
        int ans = min(down, right);
        dp[i][j] = ans;
        return ans;
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        int ans = state(0, 0, grid, n, m, dp);
        return ans;
    }