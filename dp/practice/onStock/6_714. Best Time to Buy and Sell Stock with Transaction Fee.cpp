int state(int i, int buy, auto& A, auto& dp, int fee) {
        // base case
        if(i == A.size()) {
            return 0;
        }
        if(dp[i][buy] != -1) {
            return dp[i][buy];
        }

        // transition
        int maxi = INT_MIN;
        if(buy) {
            int buyToday = (A[i] * -1) + state(i+1, 0, A, dp, fee);
            int notBuyToday = state(i+1, 1, A, dp, fee);
            maxi = max(buyToday, notBuyToday);
        } else {
            // carefull we have to pay the service charge either
            int sell = (A[i] - fee) + state(i+1, 1, A, dp, fee);
            int notSell = state(i+1, 0, A, dp, fee);
            maxi = max(sell, notSell);
        }
        dp[i][buy] = maxi;
        return maxi;
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2+1, -1));
        int ans = state(0, 1, prices, dp, fee);
        return ans;
    }