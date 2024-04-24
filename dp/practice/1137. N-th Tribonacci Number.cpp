/*
    Constraints:
        0 <= n <= 37
        The answer is guaranteed to fit within a 32-bit integer, 
        ie. answer <= 2^31 - 1.
    */

    int state(int n, auto& dp) {
        // base case
        if(n <= 1) {
            return n;
        }
        if(n == 2) {
            return 1;
        }
        if(dp[n] != -1) {
            return dp[n];
        }

        // transition
        int ans = state(n-1, dp) + state(n-2, dp) + state(n-3, dp);
        dp[n] = ans;
        return ans;
    }

    int tribonacci(int n) {
        vector<int> dp(n+1, -1);
        int ans = state(n, dp);
        return ans;
    }