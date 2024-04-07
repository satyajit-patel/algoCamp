/*
        "))(("

        Input: s = "lee(t(c)o)de)"
        Output: "lee(t(c)o)de"
        Explanation: 
        "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
    */

    string minRemoveToMakeValid(string& s) {
        int n = s.size();
        stack<int> st;
        for(int i=0; i<n; i++) {
            if(s[i] == '(') {
                st.push(i);
            } else if(s[i] == ')'){
                if(!st.empty()) {
                    st.pop();
                } else {
                    s[i] = '*';
                }
            }
        }
        while(!st.empty()) {
            int i = st.top();
            st.pop();
            s[i] = '*';
            s.erase(i, 1);
        }

        string ans = "";
        for(auto& it: s) {
            if(it != '*') {
                ans += it;
            }
        }
        return ans;
    }