/*
        Constraints:
        2 <= n <= 10^6
        1 <= cuts.length <= min(n - 1, 100)
        1 <= cuts[i] <= n - 1
    */

    int state(int i, int j, auto& a, auto& dp) {
        // base case
        if(i > j) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        // transition
        int mini = 1e9;
        for(int k=i; k<=j; k++) {
            int cost = a[j+1] - a[i-1] + state(i, k-1, a, dp) + state(k+1, j, a, dp);
            mini = min(mini, cost);
        }
        dp[i][j] = mini;
        return mini;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();

        vector<vector<int>> dp(m+1, vector<int>(m+1, -1));
        int ans = state(1, m-2, cuts, dp);
        return ans;
    }