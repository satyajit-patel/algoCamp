/*
        Input:
        N = 8
        Price[] = {1, 5, 8, 9, 10, 17, 17, 20}
        Output:
        22
        Explanation:
        The maximum obtainable value is 22 by 
        cutting in two pieces of lengths 2 and 
        6, i.e., 5+17=22.
    */
  
    int state(int i, int* val, auto& wt, int W, auto& dp) {
        // base case
        if(i >= wt.size()) {
            return 0;
        }
        if(dp[i][W] != -1) {
            return dp[i][W];
        }
    
        // transition
        int take = -1e9;
        if(W-wt[i] >= 0) {
          take = val[i] + state(i, val, wt, W-wt[i], dp);
        }
        int notTake = state(i+1, val, wt, W, dp);
        int ans = max(take, notTake);
        dp[i][W] = ans;
        return ans;
    }
  
    int cutRod(int price[], int n) {
        vector<int> weight(n);
        for(int i=0; i<n; i++) {
            weight[i] = i+1; 
        }
        
    	vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        int ans = state(0, price, weight, n, dp);
        return ans;
    }