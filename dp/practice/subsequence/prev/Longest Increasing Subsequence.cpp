class Solution {
public:
    vector<vector<int>> dp;

    int state(int i, int prev, int n, int* a) {
        // base case
        if(i >= n) {
            return 0;
        }
        if(dp[i][prev+1] != -1) {
            return dp[i][prev+1];
        }
        
        // transition
        int take = 0;
        if(prev == -1 || a[i] > a[prev]) {
            take = 1 + state(i+1, i, n, a);
        }
        int notTake = state(i+1, prev, n, a);
        int ans = max(take, notTake);
        dp[i][prev+1] = ans;
        return ans;
    }

    int longestSubsequence(int n, int a[]) {
        // // TLE
        // dp.resize(n+2, vector<int>(n+2, -1));
        // int ans = state(0, -1, n, a);
        // return ans;
        
        set<int> st;
        st.insert(a[0]);
        for(int i=1; i<n; i++) {
            if(a[i] > *st.rbegin()) {
                st.insert(a[i]);
            } else {
                st.erase(st.lower_bound(a[i]));
                st.insert(a[i]);
            }
        }
        return st.size();
    }
};