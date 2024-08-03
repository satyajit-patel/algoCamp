class Solution {
public:
    int minimumDeletions(string s) {
        int count = 0;
        stack<char> st;
        
        for(auto& it: s) {
            if(it == 'b') {
                st.push(it);
            } else if(it == 'a') {
                if(!st.empty() && st.top() == 'b') {
                    count++;
                    st.pop();
                }
            }
        }

        return count;
    }
};