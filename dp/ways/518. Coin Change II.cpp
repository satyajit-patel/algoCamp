class Solution {
public:
    vector<vector<int>> dp;
    int state(int i, int w, auto& a) {
        // base case
        if(w == 0) {
            return 1;
        }
        if(i >= a.size() || w < 0) {
            return 0;
        }
        if(dp[i][w] != -1) {
            return dp[i][w];
        }

        // transition
        return dp[i][w] = state(i, w-a[i], a) + state(i+1, w, a);
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp.resize(n+1, vector<int>(amount+1, -1));
        int ans = state(0, amount, coins);
        return ans;
    }
};