/*
        Input: text1 = "abcde", text2 = "ace" 
        Output: 3  
    */
    
    int state(int i, int j, auto& s1, auto& s2, auto& dp) {
        // base case
        if(i >= s1.size()) {
            return 0;
        }
        if(j >= s2.size()) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        // transition
        int take = 0;
        if(s1[i] == s2[j]) {
            take = 1 + state(i+1, j+1, s1, s2, dp);
        }
        int notTake = max(state(i+1, j, s1, s2, dp), state(i, j+1, s1, s2, dp));
        int ans = max(take, notTake);
        dp[i][j] = ans;
        return ans;
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, -1));
        int ans = state(0, 0, text1, text2, dp);
        return ans;
    }