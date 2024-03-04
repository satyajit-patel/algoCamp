/*
        Input: coins = [1,2,5], amount = 11
        Output: 3
        Explanation: 11 = 5 + 5 + 1

        Constraints:
        1 <= coins.length <= 12
        1 <= coins[i] <= 231 - 1
        0 <= amount <= 104
    */

    int state(int i, int amount, auto& A, auto& dp) {
        // base case
        if(amount == 0) {
            return 0;
        }
        if(amount < 0) {
            return 1e9;
        }
        if(i >= A.size()) {
            return 1e9;
        }
        if(dp[i][amount] != -1) {
            return dp[i][amount];
        }

        // transition
        int take = 1 + state(i, amount-A[i], A, dp);
        int notTake = state(i+1, amount, A, dp);
        int ans = min(take, notTake);
        dp[i][amount] = ans;
        return ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, -1));
        int ans = state(0, amount, coins, dp);
        if(ans >= 1e9) {
            return -1;
        }
        return ans;
    }