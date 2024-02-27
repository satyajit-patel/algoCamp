/*
        Input
        n = 10
        Output
        2
        Explanation
        There are two ways {5,5} and {10}.
        
        Constraints:
        1 ≤ n ≤ 10^6
    */
    
    long long state(int i, int sum, auto& A, auto& dp) {
        // base case
        if(i >= A.size()) {
            return 0;
        }
        if(sum == 0) {
            return 1;
        }
        if(sum < 0) {
            return 0;
        }
        if(dp[i][sum] != -1) {
            return dp[i][sum];
        }
        
        // transition
        int take = state(i, sum-A[i], A, dp);
        int notTake = state(i+1, sum, A, dp);
        int ans = take + notTake;
        dp[i][sum] = ans;
        return ans;
    }
    
    long long int count(long long int n) {
        vector<int> A = {3, 5, 10};
        vector<vector<int>> dp(3+1, vector<int>(n+1, -1));
    	long long ans = state(0, n, A, dp);
    	return ans;
    }