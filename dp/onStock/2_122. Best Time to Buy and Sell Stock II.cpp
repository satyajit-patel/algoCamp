/*
        note:
        buy-sell has to be done before performing
        next buy-sell

        Input: prices = [7,1,5,3,6,4]
        Output: 7
        Explanation: 
        Buy on day 2(price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
        Then buy on day 4(price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
        Total profit is 4 + 3 = 7.

        Constraints:
        1 <= prices.length <= 3 * 10^4
        0 <= prices[i] <= 10^4

        expected f(n) = O(n^2)
        our f(n) = O(n) with dp, O(2^n) with recursion
    */

    int state(int i, auto& A, int can_i_buy, auto& dp) {
        // base case
        if(i >= A.size()) {
            return 0;
        }
        if(dp[i][can_i_buy] != -1) {
            return dp[i][can_i_buy];
        }

        // transition
        int maxi = INT_MIN;
        if(can_i_buy) {
            int letsBuyToday = (A[i] * -1) + state(i+1, A, 0, dp);
            int letsNotBuyToday = state(i+1, A, 1, dp);
            maxi = max(letsBuyToday, letsNotBuyToday);
        } else {
            int letsSellToday = A[i] + state(i+1, A, 1, dp);
            int letsNotSellToday = state(i+1, A, 0, dp);
            maxi = max(letsSellToday, letsNotSellToday);
        }
        dp[i][can_i_buy] = maxi;
        return maxi;
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1, vector<int>(2+1, -1));
        int ans = state(0, prices, 1, dp);
        return ans;      
    }