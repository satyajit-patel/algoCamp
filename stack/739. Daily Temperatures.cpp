class Solution {
public:
    /*
        Input: temperatures = [73,74,75,71,69,72,76,73]
        Output: [1,1,4,2,1,1,0,0]
    */

    vector<int> NGE(vector<int>& a) {
        int n = a.size();
        stack<int> st;
        vector<int> ans(n, 0);

        for(int i=n-1; i>=0; i--) {
            // if greater comes.. leave all
            while(!st.empty() && a[i] >= a[st.top()]) {
                st.pop();
            }

            if(!st.empty()) {
                ans[i] = st.top();
            }

            st.push(i);
        }

        return ans;
    }

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> nge = NGE(temperatures);
        int n = nge.size();
        for(int i=0; i<n; i++) {
            if(nge[i] == 0) {
                continue;
            }
            nge[i] = (nge[i] - i);
        }
        return nge;
    }
};