/*
        Input: s = "acfgbd", k = 2
        Output: 4
        Explanation: The longest ideal string is "acbd". 
        The length of this string is 4, so 4 is returned.
        Note that "acfgbd" is not ideal 
        because 'c' and 'f' have a difference of 3 in alphabet order.
    */

    int state(int i, char prev, auto& s, int k, auto& dp) {
        // base case
        if(i >= s.size()) {
            return 0;
        }
        if(dp[i][prev] != -1) {
            return dp[i][prev];
        }

        // transition
        int take = 0;
        if(prev == '#' || abs(prev - s[i]) <= k) {
            take = 1 + state(i+1, s[i], s, k, dp);
        }
        int notTake = state(i+1, prev, s, k, dp);
        int ans = max(take, notTake);
        dp[i][prev] = ans;
        return ans;
    }

    int longestIdealString(string s, int k) {
        vector<vector<int>> dp(s.size()+1, vector<int>(150, -1));
        int ans = state(0, '#', s, k, dp);
        return ans;
    }