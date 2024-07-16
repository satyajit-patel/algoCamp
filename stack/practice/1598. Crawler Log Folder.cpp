class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<int> st;

        for(auto& it: logs) {
            if(it != "./") {
                if(it == "../") {
                    if(!st.empty()) {
                        st.pop();
                    }
                } else {
                    st.push(1); // anything
                }
            }
        }

        return st.size();
    }
};