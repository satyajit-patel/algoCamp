class Solution {
public:
    /*
        Constraints:
        1 <= n <= 8

            brute force
            => O(2^(2n) * 2n) = 2^16 nearly equal to 10^4 which is <= 10^8 

            optimal
            =>O(2^(2n))
    */

    // bool isvalid(string& s) {
    //     stack<char> st;
    //     for(auto& it: s) {
    //         if(it == '(') {
    //             st.push(it);
    //         } else {
    //             if(st.empty()) {
    //                 return false;
    //             }
    //             st.pop();
    //         }
    //     }
    //     return st.empty();
    // }

    // void state(string s, int n, auto& ans) {
    //     // base case
    //     if(s.size() == n) {
    //         if(isvalid(s)) {
    //             ans.push_back(s);
    //         }
    //         return;
    //     }

    //     // transition
    //     state(s+'(', n, ans);
    //     state(s+')', n, ans);
    // }

    void state(string s, int openCount, int closeCount, int n, auto& ans) {
        // base case
        if(s.size() == (2*n)) {
            ans.push_back(s);
            return;
        }

        // transition
        if(openCount < n) {
            state(s+'(', openCount+1, closeCount, n, ans);
        }
        if(closeCount < openCount) {
            state(s+')', openCount, closeCount+1, n, ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        // // brute force
        // state("", n*2, ans);

        // optimal (if n=2 then there should be only 2open and 2close braces)
        state("", 0, 0, n, ans);

        return ans;
    }
};