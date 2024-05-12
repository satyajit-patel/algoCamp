/*
        Constraints:
        1 <= energy.length <= 10^5
        -1000 <= energy[i] <= 1000
        1 <= k <= energy.length - 1
        
        f(n) = O(n * logn)
        
        Input: energy = [-2,-3,-1], k = 2
        Output: -1
        Explanation: 
        We can gain a total energy of -1 by starting from magician 2.
    */
    
    int maxi;
    int state(int i, vector<int>& a, int k, auto& dp) {
        // base case
        if(i >= a.size()) {
            return 0;
        }
        if(dp[i] != -1) {
            return dp[i];
        }
        
        // transition
        int take = a[i] + state(i+k, a, k, dp);
        state(i+1, a, k, dp);
        dp[i] = take;
        maxi = max(maxi, take);
        return take;
    }
    
    int maximumEnergy(vector<int>& energy, int k) {
        maxi = INT_MIN;
        // option i.e recursion
        int n = energy.size();
        vector<int> dp(n+1, -1);
        state(0, energy, k, dp);
        return maxi;
    }