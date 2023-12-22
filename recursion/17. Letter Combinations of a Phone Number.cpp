class Solution {
public:
    vector<string> ans;
    string digits;
    int N;
    vector<string> keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void state(int i, vector<char>& temp) {
        // base case
        if(i >= N) {
            string s = "";
            for(auto& it: temp) {
                s += it;
            }
            ans.push_back(s);
            return;
        }

        // transition
        string charsOfKeypad = keypad[digits[i]-'0'];
        for(auto& it: charsOfKeypad) {
            temp.push_back(it);
            state(i+1, temp);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string _digits) {
        ans.clear();
        digits.clear(), digits = _digits;
        N = digits.size();
        // corner case
        if(N == 0) {
            return ans;
        }
        vector<char> temp;
        state(0, temp);
        return ans;
    }
};