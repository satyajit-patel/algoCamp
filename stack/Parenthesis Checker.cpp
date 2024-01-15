class Solution {
public:
    bool ispar(string& s) {
        stack<char> st;
        for(auto& it: s) {
            if(it == '(' || it == '{' || it == '[') {
                st.push(it);
            } else {
                if(st.empty()) {
                    return false;
                }
                
                char ch = st.top();
                st.pop();
                if(it == ')' && ch != '(') {
                    return false;
                }
                else if(it == '}' && ch != '{') {
                    return false;
                } else if(it == ']' && ch != '[') {
                    return false;
                }
            }
        }
        return st.empty();
    }
};