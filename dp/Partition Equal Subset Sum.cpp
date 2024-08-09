// https://www.geeksforgeeks.org/problems/subset-sum-problem2014/1
class Solution {
public:
    /*
        Input: N = 4
        arr = {1, 5, 11, 5}
        Output: YES
        Explanation: 
        The two parts are {1, 5, 5} and {11}.
    */

    vector<int> a;
    vector<vector<int>> dp;
    int n;
    
    int state(int i, int w) {
        // base case
        if(w == 0) {
            return 1;
        }
        if(i >= n) {
            return 0;
        }
        if(dp[i][w] != -1) {
            return dp[i][w];
        }
        
        // transition
        if(w-a[i] >= 0) {
            if(state(i+1, w-a[i])) {
                return dp[i][w] = 1;
            }   
        }
        return dp[i][w] = state(i+1, w);
    }

    int equalPartition(int N, int arr[]) {
        int totSum = 0;
        for(int i=0; i<N; i++) {
            totSum += arr[i];
        }
        
        if(totSum & 1) {
            return 0;
        }
        
        int w = totSum/2;
        a.resize(N);
        for(int i=0; i<N; i++) {
            a[i] = arr[i];
        }
        dp.resize(N+1, vector<int>(w+1, -1));
        n = N;
        
        int ans = state(0, w);
        return ans;
    }
};