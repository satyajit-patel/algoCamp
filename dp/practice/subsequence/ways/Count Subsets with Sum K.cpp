#include <bits/stdc++.h> 

/*
    Input:
    4 5
    1 4 4 5
    Output: 3
    Explanation: 
    The possible ways are:
    [1, 4]
    [1, 4]
    [5]

    Constraints:
    1 <= 'n' <= 100
    0 <= 'arr[i]' <= 1000
    1 <= 'k' <= 1000

    expected f(n) = O(n * k);
    our f(n) = O(n * k) with dp
*/


int state(int i, int n, int k, vector<int>& A, vector<vector<int>>& dp) {
    // base case
    if(i == n) {
        return k == 0;
    }
    if(dp[i][k] != -1) {
        return dp[i][k];
    }

    // transition
    int take = 0;
    if(k-A[i] >= 0) {
        take = state(i+1, n, k-A[i], A, dp);
    }
    int notTake = state(i+1, n, k, A, dp);
    int ans = (take + notTake) % 1000000007;
    dp[i][k] = ans;
    return ans;
}

int subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
    return state(0, n, k, arr, dp);
}

int findWays(vector<int>& arr, int k) {
    return subsetSumToK(arr.size(), k, arr);
}