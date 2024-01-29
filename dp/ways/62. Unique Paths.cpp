class Solution {
public:
    int row;
    int col;
    vector<vector<int>> dp;

    int state(int i, int j) {
        // base case
        if(i == row-1 && j == col-1) {
            return 1;
        }
        if(i >= row) {
            return 0;
        }
        if(j >= col) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        // transition
        int down = state(i+1, j);
        int right = state(i, j+1);
        int ans = down + right;
        dp[i][j] = ans;
        return ans;
    }

    int uniquePaths(int m, int n) {
        row = m;
        col = n;
        dp.resize(m+1, vector<int>(n+1, -1));
        int ans = state(0, 0);
        return ans;
    }
};