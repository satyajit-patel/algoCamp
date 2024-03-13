 /*
        Input:
        s = "geeksforgeeks" , t = "ge"
        Output: 
        6
        Explanation: 
        There are 6 sub-sequences:[ge], [ge], [g e], [g e] [g e] and [g e].
    */
    
    int state(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
        // base case
        if(j >= t.size()) {
            return 1;
        }
        if(i >= s.size()) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        
        // transition
        int take = 0;
        if(s[i] == t[j]) {
            take = state(i+1, j+1, s, t, dp);   
        }
        int notTake = state(i+1, j, s, t, dp);
        int ans = (take + notTake) % 1000000007;
        dp[i][j] = ans;
        return ans;
    }
    
    int subsequenceCount(string& s, string& t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        int ans = state(0, 0, s, t, dp);
        return ans;
    }