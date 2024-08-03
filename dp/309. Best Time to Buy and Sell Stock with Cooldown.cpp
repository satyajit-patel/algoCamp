class Solution {
public:
    /*
        Input: prices = [1,2,3,0,2]
        Output: 3
        Explanation: transactions = [buy, sell, cooldown, buy, sell]

        observation
            1) can't buy next day after sell
            2) can't buy next until we sell
    */

    vector<vector<int>> dp;
    int state(int i, int canBuy, vector<int>& p) {
        // base case
        if(i >= p.size()) {
            return 0;
        }
        if(dp[i][canBuy] != -1) {
            return dp[i][canBuy];
        }

        // transition
        if(canBuy) {
            int buy = -p[i] + state(i+1, 0, p); // 2)
            int notBuy = state(i+1, 1, p);
            return dp[i][canBuy] = std::max(buy, notBuy);
        } else if(!canBuy) {
            int sell = p[i] + state(i+2, 1, p); // 1)
            int notSell = state(i+1, 0, p);
            return dp[i][canBuy] = std::max(sell, notSell);
        }
        return dp[i][canBuy] = -1e9;
    }

    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size()+1, vector<int>(2+1, -1));
        int ans = state(0, 1, prices);
        return ans;
    }
};