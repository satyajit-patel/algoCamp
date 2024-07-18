class Solution {
public:
    void state(int open, int close, int n, string output, vector<string>& ans) {
        // base case
        if(close == n) {
            ans.push_back(output);
            return;
        }

        // transition
        if(open < n) {
            state(open+1, close, n, output+'(', ans);
        }
        if(open > close) {
            state(open, close+1, n, output+')', ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        state(0, 0, n, "", ans);
        return ans;
    }
};