class Solution {
public:
    vector<int> dp;
    bool state(int i, string& s, set<string>& st) {
        // base case
        if(i >= s.size()) {
            return true;
        }
        if(dp[i] != -1) {
            return dp[i];
        }

        // transition
        for(int j=i; j<s.size(); j++) {
            if(st.count(s.substr(i, j-i+1))) {
                if(state(j+1, s, st)) {
                    return dp[i] = true;
                }
            }
        }
        return dp[i] = false;
    }

    bool wordBreak(string& s, vector<string>& wordDict) {
        set<string> st(wordDict.begin(), wordDict.end());
        dp.resize(s.size()+1, -1);
        bool ans = state(0, s, st);
        return ans;
    }
};