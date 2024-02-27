bool state(int i, int k, vector<int>& A, vector<vector<int>>& dp) {
    // base case
    if(i == A.size()) {
        return k == 0;
    }
    if(dp[i][k] != -1) {
        return dp[i][k];
    }

    // transition
    bool take = false;
    if(k-A[i] >= 0) {
        take = state(i+1, k-A[i], A, dp);
    }
    bool notTake = state(i+1, k, A, dp);
    bool ans = (take || notTake);
    dp[i][k] = ans;
    return ans;
}

bool canPartition(vector<int> &arr, int n) {
    int k = 0;
    for(int i=0; i<n; i++) {
        k += arr[i];
    }
    if(k%2) {
        return false;
    }

    k /= 2;
    vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
	bool ans = state(0, k, arr, dp);
    return ans;
}
