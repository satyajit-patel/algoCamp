class Solution {
public:
    /*
        Input: s = "(*))"
        Output: true

        * can be -> empty, open or close
        so we have option and option means RECURSION
    */

    vector<vector<int>> dp;
    bool state(int i, int open, string& s) {
        // base case
        if(i >= s.size()) {
            return open == 0;
        }
        if(dp[i][open] != -1) {
            return dp[i][open];
        }

        // transition
        if(s[i] == '(') {
            if(state(i+1, open+1, s)) {
                return dp[i][open] = true;
            }
        } else if(s[i] == ')') {
            if(open > 0) { // to avoid ")("
                if(state(i+1, open-1, s)) {
                    return dp[i][open] = true;
                }
            }
        } else if(s[i] == '*') {
            if(state(i+1, open+1, s)) {
                return dp[i][open] = true;
            }
            if(open > 0) {
                if(state(i+1, open-1, s)) {
                    return dp[i][open] = true;
                }
            }
            if(state(i+1, open, s)) {
                return dp[i][open] = true;
            }
        }
        return dp[i][open] = false;
    }

    bool checkValidString(string s) {
        dp.resize(s.size()+1, vector<int>(s.size()+1, -1));
        bool ans = state(0, 0, s);
        return ans;
    }
};


		// or




    vector<vector<int>> dp;
    bool state(int i, int open, string& s) {
        // base case
        if(i >= s.size()) {
            return open == 0;
        }
        if(dp[i][open] != -1) {
            return dp[i][open];
        }

        // transition
        int ans = false;
        if(s[i] == '(') {
            ans = ans || state(i+1, open+1, s);
        } else if(s[i] == ')') {
            if(open > 0) {
                ans = ans || state(i+1, open-1, s);
            }
        } else if(s[i] == '*') {
            bool openCase = state(i+1, open+1, s);
            bool closeCase = false;
            if(open > 0) {
                closeCase = state(i+1, open-1, s);
            }
            bool emptyCase = state(i+1, open, s);
            ans = ans || openCase || closeCase || emptyCase;
        }
        dp[i][open] = ans;
        return ans; 
    }

    bool checkValidString(string s) {
        dp.clear(), dp.resize(s.size()+1, vector<int>(s.size()+1, -1));
        bool ans = state(0, 0, s);
        return ans; 
    }