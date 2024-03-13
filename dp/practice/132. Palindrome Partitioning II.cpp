/*
        Input: s = "aab"
        Output: 1
        Explanation: 
        The palindrome partitioning ["aa","b"] could be produced using 1 cut.

        Constraints:
        1 <= s.length <= 2000
        s consists of lowercase English letters only.
    */

    bool ispalindrome(int i, int j, string& s) {
        while(i < j) {
            if(s[i++] != s[j--]) {return false;}
        }
        return true;
    }

    int state(int i, string& s, auto& dp) {
        // base case
        if(i >= s.size()) {
            return 0;
        }
        if(dp[i] != -1) {
            return dp[i];
        }

        // transition
        int mini = 1e9;
        for(int j=i; j<s.size(); j++) {
            if(ispalindrome(i, j, s)) {
                int cost = 1 + state(j+1, s, dp);
                mini = min(mini, cost);
            }
        }
        dp[i] = mini;
        return mini;
    }

    int minCut(string& s) {
        // let ABC
        // A|BC, AB|C, ABC| to avoid this last extra partition we need to substract 1
        vector<int> dp(s.size()+1, -1);
        int ans = state(0, s, dp) - 1;
        return ans;
    }