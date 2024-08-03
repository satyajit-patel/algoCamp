/*
        Input: coins = [1,2,5], amount = 11
        Output: 3
        Explanation: 11 = 5 + 5 + 1

    */

      class Solution {
public:
    vector<vector<int>> dp;
    int state(int i, int w, vector<int>& a) {
        // base case
        if(w == 0) {
            return 0;
        }
        if(i >= a.size()) {
            return 1e9;
        }
        if(w < 0) {
            return 1e9;
        }
        if(dp[i][w] != -1) {
            return dp[i][w];
        }

        // transition
        int take = 1 + state(i, w-a[i], a);
        int notTake = state(i+1, w, a);

        int ans = std::min(take, notTake);
        dp[i][w] = ans;
        return ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        dp.resize(coins.size()+1, vector<int>(amount+1, -1));
        int ans = state(0, amount, coins);
        if(ans >= 1e9) {
            return -1;
        }
        return ans;
    }
};