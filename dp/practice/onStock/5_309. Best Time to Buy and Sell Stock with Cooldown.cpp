int state(int i, int buy, auto& A, auto& dp) {
        // base case
        if(i >= A.size()) {
            return 0;
        }
        if(dp[i][buy] != -1) {
            return dp[i][buy];
        }

        // transition
        int maxi = INT_MIN;
        if(buy) {
            maxi = max(-A[i]+state(i+1, 0, A, dp), state(i+1, 1, A, dp));
        } else {
            // carefull, if sell, we can't buy next
            maxi = max(A[i]+state(i+2, 1, A, dp), state(i+1, 0, A, dp));
        }
        dp[i][buy] = maxi;
        return maxi;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2+1, -1));
        int ans = state(0, 1, prices, dp);
        return ans;
    }