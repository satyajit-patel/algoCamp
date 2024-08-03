#include <bits/stdc++.h> 

/*
    2
    4 5
    4 3 2 1
    5 4
    2 5 1 6 7
    Sample Output 1:
    true
    false

    Constraints:
    1 <= T <= 5
    1 <= N <= 10^3
    0 <= ARR[i] <= 10^9
    0 <= K <= 10^3
*/ 

bool state(int i, int n, int k, vector<int>& A, vector<vector<int>>& dp) {
    // base case
    if(i == n) {
        return k == 0;
    }
    if(dp[i][k] != -1) {
        return dp[i][k];
    }

    // transition
    bool take = false;
    if(k-A[i] >= 0) {
        take = state(i+1, n, k-A[i], A, dp);
    }
    bool notTake = state(i+1, n, k, A, dp);
    bool ans = take || notTake;
    dp[i][k] = ans;
    return ans;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
    return state(0, n, k, arr, dp);
}