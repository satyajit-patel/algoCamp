class Solution {
public:
    int mod = 1e9 + 7;
    vector<vector<int>> dp;
    
    int state(int n,int r) {
        if(r > n) {
            return 0;
        }
        if(n == r) {
            return 1;
        }
        if(r == 0) {
            return 1;
        }
        if(dp[n][r] != -1) {
            return dp[n][r];
        }
    
        int ans =  (state(n-1, r) + state(n-1, r-1)) % mod;
        dp[n][r] = ans;
        return ans;
    }

    int nCr(int n, int r) {
        dp.resize(n+1, vector<int>(r+1, -1));
        int ans = state(n, r);
        return ans;
    }
};
