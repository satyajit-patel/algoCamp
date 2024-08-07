class Solution {
public:
    /*
        Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
        Output: 4
        Explanation: 
        The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, 
        so the answer is 4.
        Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
        {"111001"} is an invalid subset 
        because it contains 4 1's, greater than the maximum of 3.
    */

    vector<string> s;
    vector<vector<vector<int>>> dp;

    int f(string& s) {
        int ones = 0;
        for(auto& it: s) {
            ones += ( it == '1');
        }
        return ones;
    }

    int state(int i, int n, int m) {
        // base case
        if(i >= s.size()) {
            return 0;
        }
        if(dp[i][n][m] != -1) {
            return dp[i][n][m];
        }

        // transition
        int ones = f(s[i]);
        int zero = s[i].size() - ones;
        int take = 0;
        if(n-ones >= 0 && m-zero >= 0) {
            take = 1 + state(i+1, n-ones, m-zero);
        }
        int notTake = state(i+1, n, m);
        int ans = std::max(take, notTake);
        return dp[i][n][m] = ans;
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        s = strs;
        dp.resize(s.size()+1, vector<vector<int>>(n+1, vector<int>(m+1, -1)));
        int ans = state(0, n, m);
        return ans;
    }
};