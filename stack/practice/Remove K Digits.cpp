class Solution {
public:
    string removeKdigits(string& S, int K) {
        string ans = "";
        int n = S.size();
        stack<int> st;
        for(int i=0; i<n; i++) {
            int curNum = S[i] - '0';
            while(!st.empty() && st.top() > curNum && K) {
                st.pop();
                K--;
            }
            st.push(curNum);
        }
        while(K && !st.empty()) {
            st.pop();
            K--;
        }
        
        string temp = "";
        bool flag = false;
        while(!st.empty()) {
            char curChar = st.top() + '0';
            st.pop();
            if(curChar != '0') {
                flag = true;
            }
            temp += curChar;
        }
        reverse(temp.begin(), temp.end());
        
        if(!flag) {
            return "0";
        }
        
        int i = temp.find_first_not_of('0');
        for(i; i<temp.size(); i++) {
            ans += temp[i];
        }
        return ans;
    }
};