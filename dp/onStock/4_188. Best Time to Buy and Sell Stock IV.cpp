int state(int i, int buy, int cap, auto& A, auto& dp) {
        // base case
        if(i == A.size()) {
            return 0;
        }
        if(cap == 0) {
            return 0;
        }
        if(dp[i][buy][cap] != -1) {
            return dp[i][buy][cap];
        }

        // transition
        int maxi = INT_MIN;
        if(buy) {
            // carefull here
            // when you buy your money is gone, so -ve here
            int letsBuyToday = -A[i] + state(i+1, 0, cap, A, dp); // now you can't buy before sell
            int letsNotBuyToday = state(i+1, 1, cap, A, dp); // i.e you can buy further
            maxi = max(letsBuyToday, letsNotBuyToday);
        } else {
            // after you sell, 1 transaction gets completed
            // ans your invested money comes back, so +ve here
            int letsSellToday = A[i] + state(i+1, 1, cap-1, A, dp); // now you can buy further
            int letsNotSellToday = state(i+1, 0, cap, A, dp); // i.e you still sell further
            maxi = max(letsSellToday, letsNotSellToday);
        }
        dp[i][buy][cap] = maxi;
        return maxi;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2+1, vector<int>(k+1, -1)));
        int ans = state(0, 1, k, prices, dp);
        return ans;
    }