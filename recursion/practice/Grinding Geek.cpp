class Solution {
public:
    vector<int> A;
    int n;
    vector<vector<int>> dp;
    
    int state(int i, int knapsack) {
        // base case
        if(knapsack <= 0) {
            return 0;
        }
        if(i >= n) {
            return 0;
        }
        if(dp[i][knapsack] != -1) {
            return dp[i][knapsack];
        }
        
        // transition
        int take = 0, notTake = 0;
        notTake = state(i+1, knapsack);
        if(knapsack-A[i] >= 0) {
            int loss = A[i]/10;
            if(A[i]%10) {
                loss++;
            }
            take = 1 + state(i+1, knapsack-loss);
        }
        int ans = max(take, notTake);
        dp[i][knapsack] = ans;
        return ans;
    }

    int max_courses(int _n, int total, vector<int>& cost) {
        A.clear(), A = cost;
        n = _n;
        dp.resize(n+1, vector<int>(total+1, -1));
        return state(0, total);
    }
};
