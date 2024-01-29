class Solution {
public:
    string s1;
    string s2;
    vector<vector<int>> dp;

    int state(int i, int j) {
        // base case
        if(i >= s1.size()) {
            return (s2.size()-1) - j + 1;
        }
        if(j >= s2.size()) {
            return (s1.size()-1) - i + 1;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        // transition
        int mini = 1e8;
        if(s1[i] == s2[j]) {
            mini = state(i+1, j+1);
        } else {
            int rep = state(i+1, j+1);
            int ins = state(i, j+1);
            int del = state(i+1, j);
            mini = 1 + min({rep, ins, del});
        }
        dp[i][j] = mini;
        return mini;
    }

    int minDistance(string word1, string word2) {
        s1.clear(), s1 = word1;
        s2.clear(), s2 = word2;
        dp.resize(s1.size()+1, vector<int>(s2.size()+1, -1));
        int ans = state(0, 0);
        return ans;
    }
};