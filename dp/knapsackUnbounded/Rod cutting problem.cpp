#define vi vector<int>

int f(int i, vi& A, vi& wt, int W, vector<vi>& dp) {
    // base case
    if(i >= A.size()) {
        return 0;
    }
    if(W <= 0) {
        return 0;
    }
    if(dp[i][W] != -1) {
        return dp[i][W];
    }

    // transition
    int take = INT_MIN;
    if(W-wt[i] >= 0) {
      take = A[i] + f(i, A, wt, W-wt[i], dp);
    }
    int notTake = f(i+1, A, wt, W, dp);
    int ans = max(take, notTake);
    dp[i][W] = ans;
    return ans;
}


// int state(int index, int totLength, vi& val, vector<vector<int>>& dp) {
//     // base case
//     if(totLength <= 0) {
//         return 0;
//     }
//     if(index < 0) {
//         return 0;
//     }
//     if(dp[index][totLength] != -1) {
//         return dp[index][totLength];
//     }
    
//     // transition
//     int take = INT_MIN;
//     int rodLength = index+1;
//     if(totLength-rodLength >= 0) {
//         take = val[index] + state(index, totLength-rodLength, val, dp);
//     }
//     int notTake = state(index-1, totLength, val, dp);
//     dp[index][totLength] = max(take, notTake);
//     return dp[index][totLength];
// }


int cutRod(vector<int> &price, int n) {
    vector<int> weight(n);
    for(int i=0; i<n; i++) {
        weight[i] = i+1; 
    }
	vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    // int ans = state(n-1, n, price, dp);
    int ans = f(0, price, weight, n, dp);
    return ans;
}