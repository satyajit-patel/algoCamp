/*
        Input: s = "aab"
        Output: [["a","a","b"],["aa","b"]]

        Constraints:
        1 <= s.length <= 16
        s contains only lowercase English letters.
    */

    bool ispalindrome(int i, int j, string& s) {
        while(i < j) {
            if(s[i++] != s[j--]) {return false;}
        }
        return true;
    }

    void f(int i, string& s, auto& ans, auto& temp) {
        // base case
        if(i >= s.size()) {
            ans.push_back(temp);
            return;
        }

        // recursive case
        for(int j=i; j<s.size(); j++) {
            if(ispalindrome(i, j, s)) {
                temp.push_back(s.substr(i, j-i+1));
                f(j+1, s, ans, temp);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string& s) {
        vector<vector<string>> ans;
        vector<string> temp;
        f(0, s, ans, temp);
        return ans;
    }