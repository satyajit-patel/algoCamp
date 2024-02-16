#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<long long>>>
class Solution {
public:
    long long state(int i, int j, int k, int N, vvi& mat, vvvi& dp) {
        // base case
        if(k < 0) {
            return 0;
        }
        if(i >= N || j >= N) {
            return 0;
        }
        if(i == N-1 && j == N-1) {
            return k == mat[i][j];
        }
        if(dp[i][j][k] != -1) {
            return dp[i][j][k];
        }
        
        // transition
        long long left = state(i+1, j, k-mat[i][j], N, mat, dp);
        long long right = state(i, j+1, k-mat[i][j], N, mat, dp);
        long long ans = left + right;
        dp[i][j][k] = ans;
        return ans;
    }

    long long numberOfPath(int n, int k, vector<vector<int>> arr) {
        vvvi dp(n+1, vector<vector<long long>>(n+1, vector<long long>(k+1, -1)));
        long long ans = state(0, 0, k, n, arr, dp);
        return ans;
    }
};