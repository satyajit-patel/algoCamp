class Solution {
public:
    string s1, s2, s3;
    int N1, N2, N3;
    vector<vector<vector<int>>> dp;
    
    int f(int i, int j, int k) {
        // base case
        if (i >= N1 || j >= N2 || k >= N3) {
            return 0;
        }
        if(dp[i][j][k] != -1) {
            return dp[i][j][k];
        }
    
        // transition
        if(s1[i] == s2[j] && s1[i] == s3[k]) {
            dp[i][j][k] = 1 + f(i+1, j+1, k+1);
        } else {
            dp[i][j][k] = max({f(i, j+1, k), f(i, j, k+1), f(i+1, j, k)});
        }
        return dp[i][j][k];
    }

    int LCSof3(string A, string B, string C, int n1, int n2, int n3) {
        s1.clear(), s1 = A;
        s2.clear(), s2 = B;
        s3.clear(), s3 = C;
        N1 = n1, N2 = n2, N3 = n3;
        dp.resize(n1+1, vector<vector<int>>(n2+1, vector<int>(n3+1, -1)));
        int ans = f(0, 0, 0);
        return ans;
    }
};