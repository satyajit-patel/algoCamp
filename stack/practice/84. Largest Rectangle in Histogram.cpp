class Solution {
public:
    /*
            0 1 2 3 4 5
        arr[2,1,5,6,2,3]
        nse[1,#,4,4,#,#]
        pse[#,#,1,2,1,4]

        for index 2
            => (nse[i] - pase[i] -1) * arr[i]
            => (4 - 1 -1) * 5
            => 2 * 5
            =. 10
    */

    vector<int> NSE(vector<int>& a, int n) {
        vector<int> ans(n, -1);
        stack<int> st;

        for(int i=n-1; i>=0; i--) {
            // small ele priority
            while(!st.empty() && a[i] <= a[st.top()]) {
                st.pop();
            }

            if(!st.empty()) {
                ans[i] = st.top();
            }

            st.push(i);
        }

        return ans;
    }

    vector<int> PSE(vector<int>& a, int n) {
        vector<int> ans(n, -1);
        stack<int> st;

        for(int i=0; i<n; i++) {
            // small ele priority
            while(!st.empty() && a[i] <= a[st.top()]) {
                st.pop();
            }

            if(!st.empty()) {
                ans[i] = st.top();
            }

            st.push(i);
        }
        
        return ans;
    }


    int largestRectangleArea(vector<int>& heights) {
        int maxi = INT_MIN;
        int n = heights.size();

        vector<int> pse = PSE(heights, n);
        vector<int> nse = NSE(heights, n);

        for(int i=0; i<n; i++) {
            if(nse[i] == -1) {
                nse[i] = n;
            }
            int width = (nse[i] - pse[i] - 1);
            maxi = std::max(maxi,  width * heights[i]);
        }

        return maxi;
    }
};