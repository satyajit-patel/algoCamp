vector<int> getPse(vector<int>& height) {
        int n = height.size();
        vector<int> pse(n, -1);

        stack<int> st;
        for(int i=0; i<n; i++) {
            // smaller ele gets priority
            while(!st.empty() && height[i] <= height[st.top()]) {
                st.pop();
            }

            if(!st.empty()) {
                pse[i] = st.top();
            }

            st.push(i);
        }

        return pse;
    }

    vector<int> getNse(vector<int>& height) {
        int n = height.size();
        vector<int> nse(n, -1);

        stack<int> st;
        for(int i=n-1; i>=0; i--) {
            // smaller ele gets priority
            while(!st.empty() && height[i] <= height[st.top()]) {
                st.pop();
            }

            if(!st.empty()) {
                nse[i] = st.top();
            }

            st.push(i);
        }

        return nse;
    }

    int getMaxAreaOfHistogram(vector<int>& height) {
        int maxArea = INT_MIN;
        int n = height.size();

        vector<int> nse = getNse(height);
        vector<int> pse = getPse(height);
        for(int i=0; i<n; i++) {
            if(nse[i] == -1) {
                // if height are same then height == breadth
                nse[i] = n;
            }
            int curArea = height[i] * (nse[i]-pse[i]-1);
            maxArea = max(maxArea, curArea);
        }


        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea = INT_MIN;
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> height(m, 0);
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j] == '1') {
                    height[j]++;
                } else {
                    height[j] = 0;
                }
            }
            int curArea = getMaxAreaOfHistogram(height);
            maxArea = max(maxArea, curArea);
        }

        return maxArea;
    }