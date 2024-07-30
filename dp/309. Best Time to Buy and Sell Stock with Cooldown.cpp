class Solution {
public:
    vector<vector<int>> dp;
    int state(int i, bool isbuy, vector<int>& a) {
        // base case
        if(i >= a.size()) {
            return 0;
        }
        if(dp[i][isbuy] != -1) {
            return dp[i][isbuy];
        }

        // transition
        if(isbuy) {
            int buy = -a[i] + state(i+1, !isbuy, a); // can't buy next until we sell
            int notBuy = state(i+1, isbuy, a);
            return dp[i][isbuy] = std::max(buy, notBuy);
        } else {
            int sell = +a[i] + state(i+2, !isbuy, a); // can't buy the adjacent
            int notSell = state(i+1, isbuy, a);
            return dp[i][isbuy] = std::max(sell, notSell);
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.resize(n+1, vector<int>(2+1, -1));
        int ans = state(0, true, prices);
        return ans;
    }
};