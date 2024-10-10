class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st;
        int close = 0;
        for(auto& it: s) {
            if(!st.empty() && it == ')') {
                st.pop();
            } else if(it == ')') {
                close++;
            } else if(it == '(') {
                st.push(1);
            }
        }
        int open = st.size();
        // cout << open << " " << close << endl;
        return close + open;
    }
};